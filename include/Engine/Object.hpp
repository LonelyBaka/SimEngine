#pragma once

#include <Engine/MeshRenderer.hpp>
#include <Engine/Camera.hpp>
#include <Engine/ShaderLoader.hpp>
#include <Engine/TextureLoader.hpp>

enum CollisionType{
    STATIC=btCollisionObject::CF_STATIC_OBJECT, 
    KINEMATIC=btCollisionObject::CF_KINEMATIC_OBJECT,
    NO_RESPONSE=btCollisionObject::CF_NO_CONTACT_RESPONSE,
};

class Transform {
    private:
        glm::vec3 pos, scale;
        btQuaternion rotation;
        glm::mat4 modelMatrix, translationMatrix, rotationMatrix, scaleMatrix;
    public:
        explicit Transform();
        glm::mat4 getModelMatrix();
        void setPosition(const glm::vec3& _pos);
        void setRotation(const btScalar& yaw, const btScalar& pitch, const btScalar& roll);
        void setScale(const glm::vec3& _scale);

};

class Primitive {
    private:
        static void initShader();
    protected:
        static GLuint shaderProgram;
        MeshRenderer* mesh;
        Transform transform;
        btRigidBody* rigidBody;
    public:
       explicit Primitive();
       virtual ~Primitive(){delete mesh; delete rigidBody;};
       virtual void setScale(glm::vec3 _size) = 0;
       virtual void drawElements(const std::vector<Primitive*> objects);
       void setPosition(const glm::vec3& pos);
       void setRotation(const btScalar& yaw, const btScalar& pitch, const btScalar& roll);
       void setCollisionFlags(const CollisionType& _flag) {rigidBody->setCollisionFlags(_flag);} 
       glm::vec3 getPosition() {return glm::vec3(rigidBody->getWorldTransform().getOrigin().x(),
        rigidBody->getWorldTransform().getOrigin().y(), rigidBody->getWorldTransform().getOrigin().z());}
       bool isStatic() {return (rigidBody->getCollisionFlags() == CollisionType::STATIC) ? true : false;};
       btRigidBody* getRigidBody()  {return rigidBody;}
};
