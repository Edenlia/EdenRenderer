//
// Created by zsy01 on 2023/9/7.
//

#ifndef EDENENGINE_CAMERA_HPP
#define EDENENGINE_CAMERA_HPP

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace EE {

    class Camera {
    public:
        Camera() = default;
        Camera(glm::vec3 position, glm::vec3 lookAt, glm::vec3 up, float fov, float aspect, float zNear, float zFar)
        : position(position), lookAt(lookAt), up(up), fov(fov), aspect(aspect), zNear(zNear), zFar(zFar) {};

        [[nodiscard]] glm::mat4 getViewMatrix() const { return glm::lookAtLH(position, lookAt, up); };
        [[nodiscard]] glm::mat4 getProjectionMatrix() const { return glm::perspectiveLH(fov, aspect, zNear, zFar); };
        [[nodiscard]] float getNearPlane() const { return zNear; };
        [[nodiscard]] float getFarPlane() const { return zFar; };

    private:
        glm::vec3 position;
        glm::vec3 lookAt;
        glm::vec3 up;

        float fov;
        float aspect;
        float zNear;
        float zFar;

    };

} // EE

#endif //EDENENGINE_CAMERA_HPP