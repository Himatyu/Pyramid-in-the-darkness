#include"LightValue.h"
#include"ColorTexture.h"

float4x4 matMVP[3];
float Diffuse;

struct VS_OUT
{
    float4 Position : POSITION;
	float2 Texture : TEXCOORD0;
};

VS_OUT VS(
	float3 pos : POSITION0 ,
	float2 tex : TEXCOORD0
	)
{
	VS_OUT Out;
	Out.Position = mul(float4(pos,1), matMVP[0]);
	Out.Position = mul(Out.Position, matMVP[1]);
	Out.Position = mul(Out.Position, matMVP[2]);

	Out.Texture = tex;

	return Out;
}

float4 PS(VS_OUT In) : COLOR
{
	return getDiffuseColor(In.Texture) * Diffuse;
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