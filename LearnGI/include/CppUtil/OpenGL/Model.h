#ifndef MODEL_H_
#define MODEL_H_
#include<vector>
#include<string>
using std::string;

#include<CppUtil/OpenGL/Mesh.h>

namespace CppUtil {
	namespace OpenGL {
		class Shader;
		class Model:public DObject
		{
		public:
			Model(const string & path);
			~Model() {};			

			std::vector<Mesh> meshes;
			std::string directory;
			std::vector<TextureInfo> textures_loaded;// 通过设置容器来缓存已载入的材质数据，以获得优化提升			

			virtual void Draw(const Shader& shader)const override;
			void DrawOutlining(Shader& shader, const glm::mat4& modelMat, const glm::mat4& viewMat, const glm::mat4& projMat);			
		private:		
			void loadModel(const string& path);
			void processNode(aiNode* node, const aiScene* scene);
			Mesh processMesh(aiMesh* mesh, const aiScene* scene);
			std::vector<TextureInfo> loadMaterialTextures(aiMaterial* material, aiTextureType type,
				string typeName);
			GLint TextureFromFile(const char* path, string directory);
		};		
	}
}

#endif// !MODEL_H_