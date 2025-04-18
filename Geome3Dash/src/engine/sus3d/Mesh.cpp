#include "Mesh.h"

#include "Texture.h"
#include "ShaderProgram.h"

#include <Geode/cocos/platform/CCGL.h>

namespace sus3d
{
    bool Mesh::init(aiMesh* mesh, aiMaterial* material) 
    {
        for (unsigned int i = 0; i < mesh->mNumVertices; i++) 
        {
            vertices.push_back(mesh->mVertices[i].x);
            vertices.push_back(mesh->mVertices[i].y);
            vertices.push_back(mesh->mVertices[i].z);

            if (mesh->mTextureCoords[0]) 
            {
                vertices.push_back(mesh->mTextureCoords[0][i].x);
                vertices.push_back(mesh->mTextureCoords[0][i].y);
            }
            else 
            {
                vertices.push_back(0.0f);
                vertices.push_back(0.0f);
            }

            vertices.push_back(mesh->mNormals[i].x);
            vertices.push_back(mesh->mNormals[i].y);
            vertices.push_back(mesh->mNormals[i].z);
        }

        for (unsigned int i = 0; i < mesh->mNumFaces; i++) 
        {
            aiFace face = mesh->mFaces[i];
            for (unsigned int j = 0; j < face.mNumIndices; j++) 
            {
                indices.push_back(face.mIndices[j]);
            }
        }

        initBuffers(material);

        return true;
    }

    void Mesh::initBuffers(aiMaterial* material) 
    {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(5 * sizeof(float)));
        glEnableVertexAttribArray(2);

        aiString texturePath;
        useTexture = false;
        if (material && material->GetTexture(aiTextureType_DIFFUSE, 0, &texturePath) == AI_SUCCESS) 
        {
            Texture* loadedTexture = Texture::getTextureByFilename(texturePath.C_Str());
            if (loadedTexture && loadedTexture->textureID != 0) 
            {
                texture = loadedTexture->textureID;
                useTexture = true;
            }
        }

        if (material) 
        {
            aiColor4D aiColor;
            float opacity;

            if (material->Get(AI_MATKEY_COLOR_AMBIENT, aiColor) == AI_SUCCESS)
                Ka = glm::vec3(aiColor.r, aiColor.g, aiColor.b);

            if (material->Get(AI_MATKEY_COLOR_DIFFUSE, aiColor) == AI_SUCCESS)
                Kd = glm::vec3(aiColor.r, aiColor.g, aiColor.b);

            if (material->Get(AI_MATKEY_COLOR_SPECULAR, aiColor) == AI_SUCCESS)
                Ks = glm::vec3(aiColor.r, aiColor.g, aiColor.b);

            if (material->Get(AI_MATKEY_OPACITY, opacity) == AI_SUCCESS)
                d = opacity;
        }

        glBindVertexArray(0);
    }

    Mesh* Mesh::create(aiMesh* mesh, aiMaterial* material) 
    {
        auto ret = new Mesh();
        if (!ret || !ret->init(mesh, material)) 
        {
            delete ret;
            return nullptr;
        }
        return ret;
    }

    void Mesh::render(ShaderProgram* shaderProgram) const 
    {
        if (visible) 
        {
            glBindVertexArray(VAO);
            glEnable(GL_DEPTH_TEST);
            glEnable(GL_BLEND);
            glEnable(GL_BLEND_COLOR);
            if (useTexture)
                glBindTexture(GL_TEXTURE_2D, texture);
            shaderProgram->setFloat("isTexture", float(int(useTexture)));
            shaderProgram->setVec3("Ka", isCustomKa ? customKa : Ka);
            shaderProgram->setVec3("Kd", isCustomKd ? customKd : Kd);
            shaderProgram->setVec3("Ks", isCustomKs ? customKs : Ks);
            shaderProgram->setFloat("shininess", 32);
            shaderProgram->setFloat("d", isCustomD ? customD : d);
            glDrawElements(GL_TRIANGLES, static_cast<int>(indices.size()), GL_UNSIGNED_INT, NULL);
            glBindVertexArray(0);
            glDisable(GL_DEPTH_TEST);
            glDisable(GL_BLEND);
            glDisable(GL_BLEND_COLOR);
        }
    }

    Mesh::~Mesh() {
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glDeleteBuffers(1, &EBO);
        //if (useTexture)
        //    glDeleteTextures(1, &texture);
    }
}