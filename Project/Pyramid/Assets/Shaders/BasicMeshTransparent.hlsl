#include"LightValue.h"
#include"ColorTexture.h"

float4x4 matMVP[3];
float ColorChunk[23];

struct VS_OUT
{
    float4 Position : POSITION;
	float3 Normal : TEXCOORD1;
	float2 Texture : TEXCOORD0;
};

VS_OUT VS(
	float3 pos : POSITION ,
	float3 nor : NORMAL0,
	float2 tex : TEXCOORD0
	)
{
	VS_OUT Out;
	Out.Position = mul(float4(pos,1), matMVP[0]);
	Out.Position = mul(Out.Position, matMVP[1]);
	Out.Position = mul(Out.Position, matMVP[2]);

	Out.Normal = normalize(nor.xyz);
	Out.Texture = tex;

	return Out;
}

float4 PS(VS_OUT In) : COLOR
{
	float p = dot(In.Normal, -LightDir0.xyz);
	p = p * 0.5f + 0.5f;
	p = p * p;
	float4 Out;
	Out = p * getDiffuseColor(In.Texture)
			*LightDifuse0
			*float4(ColorChunk[8],ColorChunk[9],ColorChunk[10],ColorChunk[11])//Diffuse
			*ColorChunk[21];//Transparent

	Out += float4(ColorChunk[0],ColorChunk[1],ColorChunk[2],ColorChunk[3])		//Emissive
			+float4(ColorChunk[4],ColorChunk[5],ColorChunk[6],ColorChunk[7]);	//Ambient
	return Out;
}

technique tecMain
{
    pass P0
    {
    	AlphaBlendEnable = true;
	   	SrcBlend = SRCALPHA;
	   	DestBlend = INVSRCALPHA;
    	ZWriteEnable = false;
	   
	   VertexShader = compile vs_2_0 VS();
	   PixelShader  = compile ps_2_0 PS();
    }   
}