#include"MyUtility.h"
//#include "../Utility.h"


void MyUtility::DrawSector(const CVector2D& p, const float start, const float end, const float size, const CVector4D& color)
{
	glPushAttrib(GL_ALL_ATTRIB_BITS);
	//各種機能を無効に
	//カリング無効
	glDisable(GL_CULL_FACE);
	//ライティング無効
	glDisable(GL_LIGHTING);
	//デプステスト無効
	glDisable(GL_DEPTH_TEST);
	//
	//正射投影の行列を作成
	//
	const CMatrix& mProj = CCamera::GetCurrent()->Get2DProjectionMatrix();

	const int cut = 8;
	CVector3D* vertex = new CVector3D[cut * 3];
	float* c1 = new float[cut + 1];
	float* s1 = new float[cut + 1];
	for (int i = 0; i <= cut; ++i) {
		c1[i] = cosf(Utility::Lerp(start, end, (float)i / cut));
		s1[i] = sinf(Utility::Lerp(start, end, (float)i / cut));
	}

	int idx = 0;
	for (int i = 0; i < cut; ++i)
	{
		const float& ic1 = c1[i];
		const float& ic2 = c1[i + 1];
		const float& is1 = s1[i];
		const float& is2 = s1[i + 1];
		vertex[idx] = CVector3D::zero;
		vertex[idx + 1] = CVector3D(ic1, is1, 0.0f);
		vertex[idx + 2] = CVector3D(ic2, is2, 0.0f);
		idx += 3;
	}


	CMatrix pvm = mProj * CMatrix::MTranselate(p) * CMatrix::MScale(size, size, 1);
	CShader* shader = CShader::GetInstance("Solid");
	shader->Enable();


	glUniformMatrix4fv(glGetUniformLocation(shader->GetProgram(), "PVWMatrix"), 1, GL_FALSE, pvm.f);
	glUniform4fv(glGetUniformLocation(shader->GetProgram(), "Color"), 1, color.v);

	glEnableVertexAttribArray(CShader::eVertexLocation);

	glVertexAttribPointer(CShader::eVertexLocation, 3, GL_FLOAT, GL_FALSE, 0, vertex);

	glDrawArrays(GL_TRIANGLE_FAN, 0, cut * 3);


	glDisableVertexAttribArray(CShader::eVertexLocation);

	shader->Disable();

	glEnable(GL_CULL_FACE);

	glEnable(GL_LIGHTING);

	glEnable(GL_DEPTH_TEST);

	glPopAttrib();

	delete[] vertex;
	delete[] s1;
	delete[] c1;

}

