float4x4 matP;
float4x4 matM;
float4 UV;	
float4 Diffuse;
texture Texture;

sampler Sampler = sampler_state //サンプラー
{
	Texture = <Texture>;
	MinFilter = LINEAR;
	MagFilter = LINEAR;
	MipFilter = NONE;
	AddressU = Clamp;
	AddressV = Clamp;
};

struct VS_OUT
{
	float4 f4Position : POSITION;
	float2 f2Texture : TEXCOORD0;
};

// 頂点シェーダ
VS_OUT VS(float4 pos : POSITION0, int uvIndex : BLENDINDICES0)
{
	float4 Pos;
	Pos = mul(pos, matM);
	Pos = mul(Pos, matP);

	float animUV[8] =
	{
		UV.x,UV.w,
		UV.x,UV.y,
		UV.z,UV.y,
		UV.z,UV.w
	};

	VS_OUT Out;
	Out.f4Position = Pos;
	Out.f2Texture = float2(animUV[uvIndex * 2], animUV[uvIndex * 2 + 1]);
	return Out;
}

float4 PS(VS_OUT vsOut) : COLOR
{
	return tex2D(Sampler,vsOut.f2Texture);// *Diffuse;
}

technique tecMain
{
	pass P0
	{
		AlphaBlendEnable = true;
		SrcBlend = SRCALPHA;
		DestBlend = INVSRCALPHA;
		ZWriteEnable = true;

		VertexShader = compile vs_2_0 VS();
		PixelShader = compile ps_2_0 PS();


	}
}