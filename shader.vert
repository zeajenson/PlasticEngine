#version 450
#extension GL_ARB_separate_shader_objects : enable
#extension GL_EXT_debug_printf : enable
#
layout(binding = 0) uniform UniformBufferObject{
    mat4 camera;
    mat4 model;
} ubo;

layout(location = 0) in vec3 inPosition;
//layout(location = 1) in vec2 inTexUV;

layout(location = 0) out vec4 frag_color; 

void main() {
    //gl_Position = vec4(inPosition, 1.0);
    
    //gl_Position = ubo.proj * ubo.view * ubo.model * vec4(inPosition, 1.0);
    gl_Position = ubo.camera * ubo.model * vec4(inPosition, 1.0);
    debugPrintfEXT("value of camera is %f", ubo.camera[0][0]);

    //mat4 model = ubo.model;
    frag_color = vec4(inPosition,1);
}
