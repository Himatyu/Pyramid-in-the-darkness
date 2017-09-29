texture texDiffuse;
sampler DiffuseSampler = sampler_state //�T���v���[
{
	Texture = <texDiffuse>;
};
float4 getDiffuseColor(float2 uv)	//�ėp���̂��ߊ֐���ʂ�
{
	return tex2D(DiffuseSampler, uv);
}

texture texEmissive;
sampler EmissiveSampler = sampler_state //�T���v���[
{
	Texture = <texEmissive>;
};
float4 getEmissiveColor(float2 uv)	//�ėp���̂��ߊ֐���ʂ�
{
	return tex2D(EmissiveSampler, uv);
}

texture texSpecular;
sampler SpecularSampler = sampler_state //�T���v���[
{
	Texture = <texSpecular>;
};
float4 getSpecularColor(float2 uv)	//�ėp���̂��ߊ֐���ʂ�
{
	return tex2D(SpecularSampler, uv);
}

texture texBump;
sampler BumpSampler = sampler_state //�T���v���[
{
	Texture = <texBump>;
};
float4 getBumpColor(float2 uv)	//�ėp���̂��ߊ֐���ʂ�
{
	return tex2D(BumpSampler, uv);
}