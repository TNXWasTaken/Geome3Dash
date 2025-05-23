#pragma once

#include "ShaderProgram.h"

#include <glm/glm.hpp>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <filesystem>
#include <vector>

namespace sus3d
{
    class Mesh;
    class ShaderProgram;

    class ModelProtocol {
    protected:
        glm::vec3 rotation = glm::vec3(0, 0, 0);;
        glm::vec3 position = glm::vec3(0, 0, 0);;
        glm::vec3 scale = glm::vec3(1.0);
        bool visible = 1;
    public:
        void setRotation(glm::vec3 rotation) { this->rotation = rotation; }
        void setRotationX(float rotation) { this->rotation.x = rotation; }
        void setRotationY(float rotation) { this->rotation.y = rotation; }
        void setRotationZ(float rotation) { this->rotation.z = rotation; }
        glm::vec3 getRotation() const { return this->rotation; }
        float getRotationX() const { return this->rotation.x; }
        float getRotationY() const { return this->rotation.y; }
        float getRotationZ() const { return this->rotation.z; }

        void setPosition(glm::vec3 position) { this->position = position; }
        void setPositionX(float position) { this->position.x = position; }
        void setPositionY(float position) { this->position.y = position; }
        void setPositionZ(float position) { this->position.z = position; }
        glm::vec3 getPosition() const { return this->position; }
        float getPositionX() const { return this->position.x; }
        float getPositionY() const { return this->position.y; }
        float getPositionZ() const { return this->position.z; }

        void setScale(glm::vec3 scale) { this->scale = scale; }
        void setScaleX(float scale) { this->scale.x = scale; }
        void setScaleY(float scale) { this->scale.y = scale; }
        void setScaleZ(float scale) { this->scale.z = scale; }
        glm::vec3 getScale() const { return this->scale; }
        float getScaleX() const { return this->scale.x; }
        float getScaleY() const { return this->scale.y; }
        float getScaleZ() const { return this->scale.z; }

        void setVisible(bool visible) { this->visible = visible; }
        bool getVisible() const { return this->visible; }

        virtual ~ModelProtocol() {};
    };

    class Model : public ModelProtocol {
    protected:
        virtual bool init(const aiScene* scene);
    public:
        std::vector<Mesh*> meshes;
        static Model* create(const aiScene* scene);
        void render(
            ShaderProgram* shaderProgram, 
            const glm::mat4& view, 
            const glm::vec3& lightPos, 
            const glm::vec3& lightColor, 
            const glm::vec3& cameraPos, 
            const glm::mat4& projection);

        virtual glm::mat4 prepareModelMatrix();

        virtual ~Model();
    };

    template <typename T>
    T* loadModelT(const std::filesystem::path& path) 
    {
        Assimp::Importer importer;
        const aiScene* scene = importer.ReadFile(
            path.string(),
            aiProcess_Triangulate |
            aiProcess_FlipUVs |
            aiProcess_JoinIdenticalVertices |
            aiProcess_SortByPType);
        auto model = T::create(scene);
        importer.FreeScene();
        return model;
    }

    Model* loadModel(const std::filesystem::path& path);
}
