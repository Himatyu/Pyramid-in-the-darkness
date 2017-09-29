texture texDiffuse;
sampler DiffuseSampler = sampler_state //サンプラー
{
	Texture = <texDiffuse>;
};
float4 getDiffuseColor(float2 uv)	//汎用性のため関数を通す
{
	return tex2D(DiffuseSampler, uv);
}

texture texEmissive;
sampler EmissiveSampler = sampler_state //サンプラー
{
	Texture = <texEmissive>;
};
float4 getEmissiveColor(float2 uv)	//汎用性のため関数を通す
{
	return tex2D(EmissiveSampler, uv);
}

texture texSpecular;
sampler SpecularSampler = sampler_state //サンプラー
{
	Texture = <texSpecular>;
};
float4 getSpecularColor(float2 uv)	//汎用性のため関数を通す
{
	return tex2D(SpecularSampler, uv);
}

texture texBump;
sampler BumpSampler = sampler_state //サンプラー
{
	Texture = <texBump>;
};
float4 getBumpColor(float2 uv)	//汎用性のため関数を通す
{
	return tex2D(BumpSampler, uv);
}