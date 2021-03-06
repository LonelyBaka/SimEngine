#pragma once
#include <vector>

#include <Engine/Camera.hpp>
#include <Engine/LightRenderer.hpp>

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <Engine/Renderer.hpp> 
#include <btBulletDynamicsCommon.h>
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
class MeshRenderer{
    public:
        MeshRenderer(MeshType modelType);
        ~MeshRenderer();
        GLuint getVAO(){return vao;}
        std::vector<GLuint> getIndices() {return indices;}
        
    private:
        std::vector<Vertex>vertices;
        std::vector<GLuint>indices;
        glm::mat4 modelMatrix;

        glm::vec3 position, scale;
        GLuint vao, vbo, ebo;
};