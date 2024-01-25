#pragma once

#include "defines.h"
#include "includes.h"
#include "mesh.cpp"

constexpr s64 max_frames_in_flieght = 2;

struct Instance_Functions {
        PFN_vkCreateDebugUtilsMessengerEXT vkCreateDebugUtilsMessengerEXT;
        PFN_vkEnumeratePhysicalDevices vkEnumeratePhysicalDevices;
        PFN_vkGetPhysicalDeviceFeatures vkGetPhysicalDeviceFeatures;
        PFN_vkGetPhysicalDeviceQueueFamilyProperties vkGetPhysicalDeviceQueueFamilyProperties;
        PFN_vkGetPhysicalDeviceFormatProperties vkGetPhysicalDeviceFormatProperties;
        PFN_vkGetPhysicalDeviceMemoryProperties vkGetPhysicalDeviceMemoryProperties;
        PFN_vkGetPhysicalDeviceProperties vkGetPhysicalDeviceProperties;
        PFN_vkGetPhysicalDeviceSurfaceSupportKHR vkGetPhysicalDeviceSurfaceSupportKHR;
        PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR vkGetPhysicalDeviceSurfaceCapabilitiesKHR;
        PFN_vkGetPhysicalDeviceSurfaceFormatsKHR vkGetPhysicalDeviceSurfaceFormatsKHR;
        PFN_vkGetPhysicalDeviceSurfacePresentModesKHR vkGetPhysicalDeviceSurfacePresentModesKHR;
        PFN_vkCreateDevice vkCreateDevice;
};

struct Device_Functions {
        PFN_vkGetDeviceQueue vkGetDeviceQueue;
        PFN_vkCreateSwapchainKHR vkCreateSwapchainKHR;
        PFN_vkGetSwapchainImagesKHR vkGetSwapchainImagesKHR;
        PFN_vkCreateImageView vkCreateImageView;
        PFN_vkCreateShaderModule vkCreateShaderModule;
        PFN_vkCreateDescriptorPool vkCreateDescriptorPool;
        PFN_vkCreateDescriptorSetLayout vkCreateDescriptorSetLayout;
        PFN_vkCreatePipelineLayout vkCreatePipelineLayout;
        PFN_vkCreateGraphicsPipelines vkCreateGraphicsPipelines;
        PFN_vkCreateRenderPass vkCreateRenderPass;
        PFN_vkCreateImage vkCreateImage;
        PFN_vkBindBufferMemory vkBindBufferMemory;
        PFN_vkGetBufferMemoryRequirements vkGetBufferMemoryRequirements;
        PFN_vkAllocateDescriptorSets vkAllocateDescriptorSets;
        PFN_vkUpdateDescriptorSets vkUpdateDescriptorSets;
        PFN_vkAllocateCommandBuffers vkAllocateCommandBuffers;
        PFN_vkBeginCommandBuffer vkBeginCommandBuffer;
        PFN_vkEndCommandBuffer vkEndCommandBuffer;
        PFN_vkCmdCopyBuffer vkCmdCopyBuffer;
        PFN_vkCmdBeginRenderPass vkCmdBeginRenderPass;
        PFN_vkCmdEndRenderPass vkCmdEndRenderPass;
        PFN_vkCmdSetScissor vkCmdSetScissor;
        PFN_vkCmdSetViewport vkCmdSetViewport;
        PFN_vkCmdBindPipeline vkCmdBindPipeline;
        PFN_vkCmdBindDescriptorSets vkCmdBindDescriptorSets;
        PFN_vkCmdPushConstants vkCmdPushConstants;
        PFN_vkCmdDispatch vkCmdDispatch;
        PFN_vkCmdBindVertexBuffers vkCmdBindVertexBuffers;
        PFN_vkCmdBindIndexBuffer vkCmdBindIndexBuffer;
        PFN_vkCmdDraw vkCmdDraw;
        PFN_vkCmdDrawIndexed vkCmdDrawIndexed;
        PFN_vkQueueSubmit vkQueueSubmit;
        PFN_vkDeviceWaitIdle vkDeviceWaitIdle;
        PFN_vkMapMemory vkMapMemory;
        PFN_vkUnmapMemory vkUnmapMemory;
        PFN_vkAllocateMemory vkAllocateMemory;
        PFN_vkGetImageMemoryRequirements vkGetImageMemoryRequirements;
        PFN_vkBindImageMemory vkBindImageMemory;
        PFN_vkCreateFramebuffer vkCreateFramebuffer;
        PFN_vkCreateCommandPool vkCreateCommandPool;
        PFN_vkCreateBuffer vkCreateBuffer;
        PFN_vkCreateComputePipelines vkCreateComputePipelines;
        PFN_vkCreateSemaphore vkCreateSemaphore;
        PFN_vkCreateFence vkCreateFence;
        PFN_vkWaitForFences vkWaitForFences;
        PFN_vkResetFences vkResetFences;
        PFN_vkDestroyFence vkDestroyFence; 
        PFN_vkAcquireNextImageKHR vkAcquireNextImageKHR;
        PFN_vkQueuePresentKHR vkQueuePresentKHR;
        PFN_vkQueueWaitIdle vkQueueWaitIdle;

};

struct Ubo {
        glm::mat4 camera;
        glm::mat4 model;
};

struct Triangle_Mesh{
        u32 vertex_count;
        VkBuffer vertex_buffer;
        VkDeviceMemory vertex_buffer_memory;

        u32 index_count;
        VkBuffer index_buffer;
        VkDeviceMemory index_buffer_memory;
};

struct Line_Mesh{

};

struct Render_State {
        std::pmr::polymorphic_allocator<u8> allocator;
        VkAllocationCallbacks *vulkan_allocator = nullptr;

        char **enabled_layer_names;
        u32 layer_count;
        char **enabled_extension_names;
        u32 extension_count;

        VkInstance instance;
        VkSurfaceKHR window_surface;
        Instance_Functions instance_functions;
        PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr;
        VkPhysicalDevice physical_device;
        VkPhysicalDeviceFeatures physical_device_features;

        char **enabled_device_extensions;
        u32 device_extension_count;

        VkDevice device;
        PFN_vkGetDeviceProcAddr vkGetDeviceProcAddr;
        Device_Functions device_functions;
        VkSwapchainKHR swapchain;
        VkExtent2D swapchain_extent;
        u32 swapchain_image_count;
        VkRenderPass render_pass;
        VkViewport viewport;
        VkDescriptorSet uniform_descriptor_set;
        VkPipelineLayout pipeline_layout;
        VkPipeline graphics_pipeline;
        // TODO: change everything
        u32 vertex_count;
        VkBuffer vertex_buffer;
        VkDeviceMemory vertex_buffer_memory;

        u32 index_count;
        VkBuffer index_buffer;
        VkDeviceMemory index_buffer_memory;
        
        Line_Mesh bounding_sphere_mesh;
        Line_Mesh debug_mesh;
        Line_Mesh selected_object_mesh;

        Triangle_Mesh terrain_mesh;
        Triangle_Mesh some_entity_mesh;


        VkQueue graphics_queue;
        VkQueue present_queue;
        VkFramebuffer *frame_buffers;
        VkCommandBuffer *command_buffers;

        // VkBuffer uniform_buffers[max_frames_in_flieght];
        // void * uniform_buffers_mapped_memory[max_frames_in_flieght];
        VkBuffer ubo_buffer;
        VkDeviceMemory ubo_memory;
        void *ubo_mapped_memory;

        VkSemaphore *image_available_semaphores;
        VkSemaphore *render_finished_semaphores;
        VkFence *image_in_flieght_fences;

        s64 current_frame = 0;
        Ubo ubo;
        u8 bla[1024];
};

template <typename T> T load_instance_function(Render_State *state, char const *name) noexcept { return reinterpret_cast<T>(state->vkGetInstanceProcAddr(state->instance, name)); }

template <typename T> T load_device_function(Render_State *state, char const *name) noexcept { return reinterpret_cast<T>(state->vkGetDeviceProcAddr(state->device, name)); }

void load_instance_functions(Render_State *state) {
        state->instance_functions.vkCreateDebugUtilsMessengerEXT = load_instance_function<PFN_vkCreateDebugUtilsMessengerEXT>(state, "vkCreateDebugUtilsMessengerEXT");
        state->instance_functions.vkEnumeratePhysicalDevices = load_instance_function<PFN_vkEnumeratePhysicalDevices>(state, "vkEnumeratePhysicalDevices");
        state->instance_functions.vkGetPhysicalDeviceFeatures = load_instance_function<PFN_vkGetPhysicalDeviceFeatures>(state, "vkGetPhysicalDeviceFeatures");
        state->instance_functions.vkGetPhysicalDeviceQueueFamilyProperties = load_instance_function<PFN_vkGetPhysicalDeviceQueueFamilyProperties>(state, "vkGetPhysicalDeviceQueueFamilyProperties");
        state->instance_functions.vkGetPhysicalDeviceFormatProperties = load_instance_function<PFN_vkGetPhysicalDeviceFormatProperties>(state, "vkGetPhysicalDeviceFormatProperties");
        state->instance_functions.vkGetPhysicalDeviceMemoryProperties = load_instance_function<PFN_vkGetPhysicalDeviceMemoryProperties>(state, "vkGetPhysicalDeviceMemoryProperties");
        state->instance_functions.vkGetPhysicalDeviceProperties = load_instance_function<PFN_vkGetPhysicalDeviceProperties>(state, "vkGetPhysicalDeviceProperties");
        state->instance_functions.vkGetPhysicalDeviceSurfaceSupportKHR = load_instance_function<PFN_vkGetPhysicalDeviceSurfaceSupportKHR>(state, "vkGetPhysicalDeviceSurfaceSupportKHR");
        state->instance_functions.vkGetPhysicalDeviceSurfaceCapabilitiesKHR = load_instance_function<PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>(state, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR");
        state->instance_functions.vkGetPhysicalDeviceSurfaceFormatsKHR = load_instance_function<PFN_vkGetPhysicalDeviceSurfaceFormatsKHR>(state, "vkGetPhysicalDeviceSurfaceFormatsKHR");
        state->instance_functions.vkGetPhysicalDeviceSurfacePresentModesKHR = load_instance_function<PFN_vkGetPhysicalDeviceSurfacePresentModesKHR>(state, "vkGetPhysicalDeviceSurfacePresentModesKHR");
        state->instance_functions.vkCreateDevice = load_instance_function<PFN_vkCreateDevice>(state, "vkCreateDevice");
}

void load_device_functions(Render_State *state) {
        state->vkGetDeviceProcAddr = load_instance_function<PFN_vkGetDeviceProcAddr>(state, "vkGetDeviceProcAddr");
        state->device_functions.vkGetDeviceQueue = load_device_function<PFN_vkGetDeviceQueue>(state, "vkGetDeviceQueue");
        state->device_functions.vkCreateSwapchainKHR = load_device_function<PFN_vkCreateSwapchainKHR>(state, "vkCreateSwapchainKHR");
        state->device_functions.vkGetSwapchainImagesKHR = load_device_function<PFN_vkGetSwapchainImagesKHR>(state, "vkGetSwapchainImagesKHR");
        state->device_functions.vkCreateImageView = load_device_function<PFN_vkCreateImageView>(state, "vkCreateImageView");
        state->device_functions.vkCreateShaderModule = load_device_function<PFN_vkCreateShaderModule>(state, "vkCreateShaderModule");
        state->device_functions.vkCreateDescriptorPool = load_device_function<PFN_vkCreateDescriptorPool>(state, "vkCreateDescriptorPool");
        state->device_functions.vkCreateDescriptorSetLayout = load_device_function<PFN_vkCreateDescriptorSetLayout>(state, "vkCreateDescriptorSetLayout");
        state->device_functions.vkCreatePipelineLayout = load_device_function<PFN_vkCreatePipelineLayout>(state, "vkCreatePipelineLayout");
        state->device_functions.vkCreateGraphicsPipelines = load_device_function<PFN_vkCreateGraphicsPipelines>(state, "vkCreateGraphicsPipelines");
        state->device_functions.vkCreateRenderPass = load_device_function<PFN_vkCreateRenderPass>(state, "vkCreateRenderPass");
        state->device_functions.vkCreateImage = load_device_function<PFN_vkCreateImage>(state, "vkCreateImage");
        state->device_functions.vkBindBufferMemory = load_device_function<PFN_vkBindBufferMemory>(state, "vkBindBufferMemory");
        state->device_functions.vkGetBufferMemoryRequirements = load_device_function<PFN_vkGetBufferMemoryRequirements>(state, "vkGetBufferMemoryRequirements");
        state->device_functions.vkAllocateDescriptorSets = load_device_function<PFN_vkAllocateDescriptorSets>(state, "vkAllocateDescriptorSets");
        state->device_functions.vkUpdateDescriptorSets = load_device_function<PFN_vkUpdateDescriptorSets>(state, "vkUpdateDescriptorSets");
        state->device_functions.vkAllocateCommandBuffers = load_device_function<PFN_vkAllocateCommandBuffers>(state, "vkAllocateCommandBuffers");
        state->device_functions.vkBeginCommandBuffer = load_device_function<PFN_vkBeginCommandBuffer>(state, "vkBeginCommandBuffer");
        state->device_functions.vkEndCommandBuffer = load_device_function<PFN_vkEndCommandBuffer>(state, "vkEndCommandBuffer");
        state->device_functions.vkCmdCopyBuffer = load_device_function<PFN_vkCmdCopyBuffer>(state, "vkCmdCopyBuffer");
        state->device_functions.vkCmdBeginRenderPass = load_device_function<PFN_vkCmdBeginRenderPass>(state, "vkCmdBeginRenderPass");
        state->device_functions.vkCmdEndRenderPass = load_device_function<PFN_vkCmdEndRenderPass>(state, "vkCmdEndRenderPass");
        state->device_functions.vkCmdSetScissor = load_device_function<PFN_vkCmdSetScissor>(state, "vkCmdSetScissor");
        state->device_functions.vkCmdSetViewport = load_device_function<PFN_vkCmdSetViewport>(state, "vkCmdSetViewport");
        state->device_functions.vkCmdBindPipeline = load_device_function<PFN_vkCmdBindPipeline>(state, "vkCmdBindPipeline");
        state->device_functions.vkCmdBindDescriptorSets = load_device_function<PFN_vkCmdBindDescriptorSets>(state, "vkCmdBindDescriptorSets");
        state->device_functions.vkCmdDispatch = load_device_function<PFN_vkCmdDispatch>(state, "vkCmdDispatch");
        state->device_functions.vkCmdBindVertexBuffers = load_device_function<PFN_vkCmdBindVertexBuffers>(state, "vkCmdBindVertexBuffers");
        state->device_functions.vkCmdBindIndexBuffer = load_device_function<PFN_vkCmdBindIndexBuffer>(state, "vkCmdBindIndexBuffer");
        state->device_functions.vkCmdPushConstants = load_device_function<PFN_vkCmdPushConstants>(state, "vkCmdPushConstants");
        state->device_functions.vkCmdDraw = load_device_function<PFN_vkCmdDraw>(state, "vkCmdDraw");
        state->device_functions.vkCmdDrawIndexed = load_device_function<PFN_vkCmdDrawIndexed>(state, "vkCmdDrawIndexed");
        state->device_functions.vkQueueSubmit = load_device_function<PFN_vkQueueSubmit>(state, "vkQueueSubmit");
        state->device_functions.vkDeviceWaitIdle = load_device_function<PFN_vkDeviceWaitIdle>(state, "vkDeviceWaitIdle");
        state->device_functions.vkMapMemory = load_device_function<PFN_vkMapMemory>(state, "vkMapMemory");
        state->device_functions.vkUnmapMemory = load_device_function<PFN_vkUnmapMemory>(state, "vkUnmapMemory");
        state->device_functions.vkAllocateMemory = load_device_function<PFN_vkAllocateMemory>(state, "vkAllocateMemory");
        state->device_functions.vkGetImageMemoryRequirements = load_device_function<PFN_vkGetImageMemoryRequirements>(state, "vkGetImageMemoryRequirements");
        state->device_functions.vkBindImageMemory = load_device_function<PFN_vkBindImageMemory>(state, "vkBindImageMemory");
        state->device_functions.vkCreateFramebuffer = load_device_function<PFN_vkCreateFramebuffer>(state, "vkCreateFramebuffer");
        state->device_functions.vkCreateCommandPool = load_device_function<PFN_vkCreateCommandPool>(state, "vkCreateCommandPool");
        state->device_functions.vkCreateBuffer = load_device_function<PFN_vkCreateBuffer>(state, "vkCreateBuffer");
        state->device_functions.vkCreateComputePipelines = load_device_function<PFN_vkCreateComputePipelines>(state, "vkCreateComputePipelines");
        state->device_functions.vkCreateSemaphore = load_device_function<PFN_vkCreateSemaphore>(state, "vkCreateSemaphore");
        state->device_functions.vkCreateFence = load_device_function<PFN_vkCreateFence>(state, "vkCreateFence");
        state->device_functions.vkAcquireNextImageKHR = load_device_function<PFN_vkAcquireNextImageKHR>(state, "vkAcquireNextImageKHR");
        state->device_functions.vkQueuePresentKHR = load_device_function<PFN_vkQueuePresentKHR>(state, "vkQueuePresentKHR");
        state->device_functions.vkQueueWaitIdle = load_device_function<PFN_vkQueueWaitIdle>(state, "vkQueueWaitIdle");
        state->device_functions.vkWaitForFences = load_device_function<PFN_vkWaitForFences>(state, "vkWaitForFences");
        state->device_functions.vkResetFences = load_device_function<PFN_vkResetFences>(state, "vkResetFences");
        state->device_functions.vkDestroyFence = load_device_function<PFN_vkDestroyFence>(state, "vkDestroyFence");
}

static VKAPI_ATTR VkBool32 VKAPI_CALL debug_callback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT *pCallbackData, void *pUserData) {
        std::puts(std::format("validation layer {} :{} \n", string_VkDebugUtilsMessageSeverityFlagsEXT(messageSeverity), pCallbackData->pMessage).c_str());
        return VK_FALSE;
}

template <typename T> static T load_vulkan_function(const char *name) { return reinterpret_cast<T>(glfwGetInstanceProcAddress(nullptr, name)); }

template <typename T> static T load_vulkan_function(VkInstance instance, const char *name) { return reinterpret_cast<T>(glfwGetInstanceProcAddress(instance, name)); }

auto create_basic_graphics_pipeline(Render_State *state) {}

auto initalize(Render_State *state, GLFWwindow *window) {
        puts("initalizeing vulkan render state");
        auto app_info = VkApplicationInfo{
                .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
                .pNext = nullptr,
                .pApplicationName = "plastic",
                .applicationVersion = VK_MAKE_VERSION(1, 0, 0),
                .pEngineName = "plastic",
                .engineVersion = VK_MAKE_VERSION(1, 0, 0),
                .apiVersion = VK_API_VERSION_1_3,
        };

        std::vector<char const *> extension_names = {VK_EXT_DEBUG_UTILS_EXTENSION_NAME};

        u32 glfw_extension_count;
        auto const glfw_extensions = glfwGetRequiredInstanceExtensions(&glfw_extension_count);
        extension_names.insert(extension_names.end(), glfw_extensions, glfw_extensions + glfw_extension_count);

        for (auto &&name : extension_names) {
                std::puts(name);
        }

        std::vector<char const *> layer_names = {"VK_LAYER_KHRONOS_validation"};
        auto instantce_info = VkInstanceCreateInfo{
                .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
                .pNext = nullptr,
                .flags = {},
                .pApplicationInfo = &app_info,
                .enabledLayerCount = static_cast<uint32_t>(layer_names.size()),
                .ppEnabledLayerNames = layer_names.data(),
                .enabledExtensionCount = static_cast<uint32_t>(extension_names.size()),
                .ppEnabledExtensionNames = extension_names.data(),
        };

        auto const vkCreateInstance = load_vulkan_function<PFN_vkCreateInstance>("vkCreateInstance");

        if (vkCreateInstance(&instantce_info, state->vulkan_allocator, &state->instance) not_eq VK_SUCCESS) {
                std::puts("Unable to create vulkan instance.\n");
        }
        state->vkGetInstanceProcAddr = load_vulkan_function<PFN_vkGetInstanceProcAddr>(state->instance, "vkGetInstanceProcAddr");
        load_instance_functions(state);
        auto debug_messenger_info = VkDebugUtilsMessengerCreateInfoEXT{
                .sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT,
                .pNext = nullptr,
                .flags = {},
                .messageSeverity = /* VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT | */ VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT,
                .messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_DEVICE_ADDRESS_BINDING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT,
                .pfnUserCallback = debug_callback,
        };

        VkDebugUtilsMessengerEXT debug_utils_messenger;
        if (not state->instance_functions.vkCreateDebugUtilsMessengerEXT) {
                std::puts("unable to load debug utils messenger.\n");
        } else if (state->instance_functions.vkCreateDebugUtilsMessengerEXT(state->instance, &debug_messenger_info, state->vulkan_allocator, &debug_utils_messenger) not_eq VK_SUCCESS) {
                std::puts("unable to create debug utils messenger.\n");
        }

        if (glfwCreateWindowSurface(state->instance, window, state->vulkan_allocator, &state->window_surface) not_eq VK_SUCCESS) {
                std::puts("Unable to get surface");
                std::terminate();
        }

        uint32_t device_count = 0;
        if (state->instance_functions.vkEnumeratePhysicalDevices(state->instance, &device_count, nullptr) not_eq VK_SUCCESS or device_count == 0) {
                std::puts("no physical device.");
                std::terminate();
        }
        auto physical_devices = std::vector<VkPhysicalDevice>(device_count);
        state->instance_functions.vkEnumeratePhysicalDevices(state->instance, &device_count, physical_devices.data());

        //TODO: choose a proper rendering device.
        state->physical_device = physical_devices[0];

        auto const [graphics_index, present_index, compute_index] = std::invoke([&] {
                uint32_t property_count = 0;
                state->instance_functions.vkGetPhysicalDeviceQueueFamilyProperties(state->physical_device, &property_count, nullptr);
                VkQueueFamilyProperties properties[property_count];
                state->instance_functions.vkGetPhysicalDeviceQueueFamilyProperties(state->physical_device, &property_count, properties);

                struct {
                        int32_t graphics_index;
                        int32_t present_index;
                        int32_t compute_index;
                } indices{-1, -1, -1};

                for (auto i = 0; i < property_count; ++i) {
                        auto const &property = properties[i];
                        if (indices.graphics_index < 0 and property.queueFlags & VkQueueFlagBits::VK_QUEUE_GRAPHICS_BIT) {
                                indices.graphics_index = i;
                        }
                        if (indices.compute_index < 0 and property.queueFlags & VK_QUEUE_COMPUTE_BIT) {
                                indices.compute_index = i;
                        }
                        VkBool32 surface_is_supported = VK_FALSE;
                        if (state->instance_functions.vkGetPhysicalDeviceSurfaceSupportKHR(state->physical_device, i, state->window_surface, &surface_is_supported) not_eq VK_SUCCESS) {
                                std::puts(std::format("device surface support for queue index {} is not supported", i).c_str());
                                continue;
                        }
                        if (indices.present_index < 0 and surface_is_supported) {
                                indices.present_index = i;
                        }

                        if (indices.graphics_index >= 0 and indices.present_index >= 0 and indices.compute_index >= 0) {
                                break;
                        }
                }
                return indices;
        });

        float graphics_queue_prioraties[] = {1.0f};

        char const *device_extensions[1] = {VK_KHR_SWAPCHAIN_EXTENSION_NAME};

        state->instance_functions.vkGetPhysicalDeviceFeatures(state->physical_device, &state->physical_device_features);

        auto const queue_create_infos = std::array{
                VkDeviceQueueCreateInfo{
                        .sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO,
                        .pNext = nullptr,
                        .flags = {},
                        .queueFamilyIndex = static_cast<uint32_t>(graphics_index),
                        .queueCount = 1,
                        .pQueuePriorities = graphics_queue_prioraties,
                },
        };

        auto const device_create_info = VkDeviceCreateInfo{
                .sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO,
                .pNext = nullptr,
                .flags = {},
                .queueCreateInfoCount = queue_create_infos.size(),
                .pQueueCreateInfos = queue_create_infos.data(),
                .enabledLayerCount = static_cast<uint32_t>(layer_names.size()),
                .ppEnabledLayerNames = layer_names.data(),
                .enabledExtensionCount = 1,
                .ppEnabledExtensionNames = device_extensions,
                .pEnabledFeatures = &state->physical_device_features,
        };

        if (state->instance_functions.vkCreateDevice(state->physical_device, &device_create_info, state->vulkan_allocator, &state->device) not_eq VK_SUCCESS) {
                puts("unable to create device");
                exit(42);
        }
        puts("loading device functions.");
        load_device_functions(state);
        auto const vkGetDeviceQueue = state->device_functions.vkGetDeviceQueue;
        auto const vkCreateSwapchainKHR = state->device_functions.vkCreateSwapchainKHR;
        auto const vkGetSwapchainImagesKHR = state->device_functions.vkGetSwapchainImagesKHR;
        auto const vkCreateImageView = state->device_functions.vkCreateImageView;
        auto const vkCreateShaderModule = state->device_functions.vkCreateShaderModule;
        auto const vkCreateDescriptorPool = state->device_functions.vkCreateDescriptorPool;
        auto const vkCreateDescriptorSetLayout = state->device_functions.vkCreateDescriptorSetLayout;
        auto const vkCreatePipelineLayout = state->device_functions.vkCreatePipelineLayout;
        auto const vkCreateGraphicsPipelines = state->device_functions.vkCreateGraphicsPipelines;
        auto const vkCreateRenderPass = state->device_functions.vkCreateRenderPass;
        auto const vkCreateImage = state->device_functions.vkCreateImage;
        auto const vkBindBufferMemory = state->device_functions.vkBindBufferMemory;
        auto const vkGetBufferMemoryRequirements = state->device_functions.vkGetBufferMemoryRequirements;
        auto const vkAllocateDescriptorSets = state->device_functions.vkAllocateDescriptorSets;
        auto const vkUpdateDescriptorSets = state->device_functions.vkUpdateDescriptorSets;
        auto const vkAllocateCommandBuffers = state->device_functions.vkAllocateCommandBuffers;
        auto const vkBeginCommandBuffer = state->device_functions.vkBeginCommandBuffer;
        auto const vkEndCommandBuffer = state->device_functions.vkEndCommandBuffer;
        auto const vkCmdCopyBuffer = state->device_functions.vkCmdCopyBuffer;
        auto const vkCmdBeginRenderPass = state->device_functions.vkCmdBeginRenderPass;
        auto const vkCmdEndRenderPass = state->device_functions.vkCmdEndRenderPass;
        auto const vkCmdSetScissor = state->device_functions.vkCmdSetScissor;
        auto const vkCmdSetViewport = state->device_functions.vkCmdSetViewport;
        auto const vkCmdBindPipeline = state->device_functions.vkCmdBindPipeline;
        auto const vkCmdBindDescriptorSets = state->device_functions.vkCmdBindDescriptorSets;
        auto const vkCmdDispatch = state->device_functions.vkCmdDispatch;
        auto const vkCmdBindVertexBuffers = state->device_functions.vkCmdBindVertexBuffers;
        auto const vkCmdBindIndexBuffer = state->device_functions.vkCmdBindIndexBuffer;
        auto const vkCmdDraw = state->device_functions.vkCmdDraw;
        auto const vkCmdDrawIndexed = state->device_functions.vkCmdDrawIndexed;
        auto const vkQueueSubmit = state->device_functions.vkQueueSubmit;
        auto const vkDeviceWaitIdle = state->device_functions.vkDeviceWaitIdle;
        auto const vkMapMemory = state->device_functions.vkMapMemory;
        auto const vkUnmapMemory = state->device_functions.vkUnmapMemory;
        auto const vkAllocateMemory = state->device_functions.vkAllocateMemory;
        auto const vkGetImageMemoryRequirements = state->device_functions.vkGetImageMemoryRequirements;
        auto const vkBindImageMemory = state->device_functions.vkBindImageMemory;
        auto const vkCreateFramebuffer = state->device_functions.vkCreateFramebuffer;
        auto const vkCreateCommandPool = state->device_functions.vkCreateCommandPool;
        auto const vkCreateBuffer = state->device_functions.vkCreateBuffer;
        auto const vkCreateComputePipelines = state->device_functions.vkCreateComputePipelines;
        auto const vkCreateSemaphore = state->device_functions.vkCreateSemaphore;
        auto const vkCreateFence = state->device_functions.vkCreateFence;
        auto const vkAcquireNextImageKHR = state->device_functions.vkAcquireNextImageKHR;
        auto const vkQueuePresentKHR = state->device_functions.vkQueuePresentKHR;
        auto const vkQueueWaitIdle = state->device_functions.vkQueueWaitIdle;
        auto const vkWaitForFences = state->device_functions.vkWaitForFences;
        auto const vkResetFences = state->device_functions.vkResetFences;

        vkGetDeviceQueue(state->device, graphics_index, 0, &state->graphics_queue);

        VkSurfaceCapabilitiesKHR surface_capabilities;
        if (state->instance_functions.vkGetPhysicalDeviceSurfaceCapabilitiesKHR(state->physical_device, state->window_surface, &surface_capabilities) not_eq VK_SUCCESS) {
                puts("unable to get surface capabilities");
                std::exit(39393);
        }

        uint32_t format_count = 0;
        if (state->instance_functions.vkGetPhysicalDeviceSurfaceFormatsKHR(state->physical_device, state->window_surface, &format_count, nullptr) not_eq VK_SUCCESS) {
                std::exit(39393);
        }
        VkSurfaceFormatKHR formats[format_count];
        state->instance_functions.vkGetPhysicalDeviceSurfaceFormatsKHR(state->physical_device, state->window_surface, &format_count, formats);
        auto const surface_format = formats[0];

        uint32_t present_mode_count = 0;
        if (state->instance_functions.vkGetPhysicalDeviceSurfacePresentModesKHR(state->physical_device, state->window_surface, &present_mode_count, nullptr) not_eq VK_SUCCESS) {
                std::exit(39393);
        }
        VkPresentModeKHR present_modes[present_mode_count];
        state->instance_functions.vkGetPhysicalDeviceSurfacePresentModesKHR(state->physical_device, state->window_surface, &format_count, present_modes);
        auto const surface_present_mode = present_modes[0];

        int32_t window_width, window_height;
        glfwGetFramebufferSize(window, &window_width, &window_height);

        auto min_image_extent = surface_capabilities.minImageExtent;
        auto max_image_extent = surface_capabilities.maxImageExtent;
        state->swapchain_extent = VkExtent2D{
                .width = std::clamp<uint32_t>(static_cast<uint32_t>(window_width), min_image_extent.width, max_image_extent.width),
                .height = std::clamp<uint32_t>(static_cast<uint32_t>(window_height), min_image_extent.height, max_image_extent.height),
        };

        uint32_t image_array_layers = 0;

        auto sharing_mode = VK_SHARING_MODE_EXCLUSIVE;
        auto queue_family_indices = std::vector<uint32_t>();
        queue_family_indices.push_back(graphics_index);
        queue_family_indices.push_back(compute_index);
        if (graphics_index not_eq present_index) {
                queue_family_indices.push_back(present_index);
                sharing_mode = VK_SHARING_MODE_CONCURRENT;
        }

        auto const swapchain_create_info = VkSwapchainCreateInfoKHR{
                .sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR,
                .pNext = nullptr,
                .flags = {},
                .surface = state->window_surface,
                .minImageCount = surface_capabilities.minImageCount + 1,
                .imageFormat = surface_format.format,
                .imageColorSpace = surface_format.colorSpace,
                .imageExtent = state->swapchain_extent,
                .imageArrayLayers = 1,
                .imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT,
                .imageSharingMode = sharing_mode,
                .queueFamilyIndexCount = static_cast<uint32_t>(queue_family_indices.size()),
                .pQueueFamilyIndices = queue_family_indices.data(),
                .preTransform = surface_capabilities.currentTransform,
                .compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR,
                .presentMode = surface_present_mode,
                .clipped = VK_TRUE,
                .oldSwapchain = nullptr,
        };

        if (vkCreateSwapchainKHR(state->device, &swapchain_create_info, state->vulkan_allocator, &state->swapchain) not_eq VK_SUCCESS) {
                std::puts("unable to create swapchain");
                std::exit(2323232);
        }

        if (vkGetSwapchainImagesKHR(state->device, state->swapchain, &state->swapchain_image_count, nullptr) not_eq VK_SUCCESS) {
                std::exit(2424242);
        }

        auto swapchain_images = std::vector<VkImage>(state->swapchain_image_count);
        vkGetSwapchainImagesKHR(state->device, state->swapchain, &state->swapchain_image_count, swapchain_images.data());

        auto swapchain_image_views = std::vector<VkImageView>(state->swapchain_image_count);
        for (auto i = 0; i < state->swapchain_image_count; ++i) {
                auto const subresource_range = VkImageSubresourceRange{
                        .aspectMask = VkImageAspectFlagBits::VK_IMAGE_ASPECT_COLOR_BIT,
                        .baseMipLevel = 0,
                        .levelCount = 1,
                        .baseArrayLayer = 0,
                        .layerCount = 1,
                };
                auto const image_view_create_info = VkImageViewCreateInfo{
                        .sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
                        .pNext = nullptr,
                        .flags = {},
                        .image = swapchain_images[i],
                        .viewType = VK_IMAGE_VIEW_TYPE_2D,
                        .format = surface_format.format,
                        .components = {},
                        .subresourceRange = subresource_range,
                };
                if (vkCreateImageView(state->device, &image_view_create_info, state->vulkan_allocator, &swapchain_image_views[i]) not_eq VK_SUCCESS) {
                        std::puts("unable to create swapchain image views");
                        std::exit(52);
                }
        }

        auto const color_attachment = VkAttachmentDescription{
                .flags = {},
                .format = surface_format.format,
                .samples = VK_SAMPLE_COUNT_1_BIT,
                .loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR,
                .storeOp = VK_ATTACHMENT_STORE_OP_STORE,
                .stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE,
                .stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE,
                .initialLayout = VK_IMAGE_LAYOUT_UNDEFINED,
                .finalLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,
        };

        auto const color_attachment_refrence = VkAttachmentReference{
                .attachment = 0,
                .layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,
        };

        // auto depth_format = std::optional<VkFormat>(std::nullopt);
        // for (auto format : {VK_FORMAT_D32_SFLOAT, VK_FORMAT_D32_SFLOAT_S8_UINT,
        // VK_FORMAT_D24_UNORM_S8_UINT}) {
        //         VkFormatProperties physical_device_format_properties;
        //         get_physical_device_format_properties(physical_device, format,
        //         &physical_device_format_properties); if
        //         ((physical_device_format_properties.optimalTilingFeatures &
        //         VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT) > 0) {
        //                 depth_format = format;
        //                 break;
        //         }
        // }
        // if (not depth_format) {
        //         std::puts("unable to find depth format");
        //         exit(7894238);
        // }

        // auto const depth_attachment = VkAttachmentDescription{
        //         .flags = {},
        //         .format = depth_format.value(),
        //         .samples = VK_SAMPLE_COUNT_1_BIT,
        //         .loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR,
        //         .storeOp = VK_ATTACHMENT_STORE_OP_STORE,
        //         .stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE,
        //         .stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE,
        //         .initialLayout = VK_IMAGE_LAYOUT_UNDEFINED,
        //         .finalLayout =
        //         VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL,
        // };

        // auto const depth_attachement_refrence = VkAttachmentReference{
        //         .attachment = 1,
        //         .layout =
        //         VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL,
        // };

        auto const subpass = VkSubpassDescription{
                .flags = {},
                .pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS,
                .colorAttachmentCount = 1,
                .pColorAttachments = &color_attachment_refrence,
        };

        VkPipelineStageFlags stage_mask_bits = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT | VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT;

        auto const subpass_dependency = VkSubpassDependency{
                .srcSubpass = VK_SUBPASS_EXTERNAL,
                .dstSubpass = 0,
                .srcStageMask = stage_mask_bits,
                .dstStageMask = stage_mask_bits,
                .srcAccessMask = {},
                .dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT | VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT,
                .dependencyFlags = {},
        };

        auto const attachemnts = std::array{
                color_attachment,
                // depth_attachment
        };

        auto const render_pass_create_info = VkRenderPassCreateInfo{
                .sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO,
                .pNext = nullptr,
                .flags = {},
                .attachmentCount = attachemnts.size(),
                .pAttachments = attachemnts.data(),
                .subpassCount = 1,
                .pSubpasses = &subpass,
                .dependencyCount = 1,
                .pDependencies = &subpass_dependency,
        };

        if (not vkCreateRenderPass)
                exit(123);
        if (vkCreateRenderPass(state->device, &render_pass_create_info, state->vulkan_allocator, &state->render_pass) not_eq VK_SUCCESS) {
                std::puts("unable to create render pass");
                std::exit(1);
        }

        auto create_shader_module = [&vkCreateShaderModule, state](std::filesystem::path path) -> VkShaderModule {
                std::puts("creating shader module");
                auto file = std::ifstream(path.string(), std::ios::ate | std::ios::binary);
                auto const fileSize = (size_t)file.tellg();
                auto buffer = std::vector<char>(fileSize);
                file.seekg(0);
                file.read(buffer.data(), fileSize);
                std::puts(std::format("loading shader {} with bytecount {}", path.string(), buffer.size()).c_str());
                auto const shader_module_create_info = VkShaderModuleCreateInfo{
                        .sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO,
                        .pNext = nullptr,
                        .flags = {},
                        .codeSize = buffer.size(),
                        .pCode = reinterpret_cast<uint32_t const *>(buffer.data()),
                };
                VkShaderModule module;
                if (vkCreateShaderModule(state->device, &shader_module_create_info, state->vulkan_allocator, &module)) {
                        std::puts("unable to create shader module");
                        std::exit(420);
                }
                return module;
        };

        auto const vertex_shader_module = create_shader_module("shader.vert.spv");
        auto const vertex_shader_stage_create_info = VkPipelineShaderStageCreateInfo{
                .sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO,
                .pNext = nullptr,
                .flags = {},
                .stage = VK_SHADER_STAGE_VERTEX_BIT,
                .module = vertex_shader_module,
                .pName = "main",
        };

        auto const fragment_shader_module = create_shader_module("shader.frag.spv");
        auto const fragment_shader_stage_create_info = VkPipelineShaderStageCreateInfo{
                .sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO,
                .pNext = nullptr,
                .flags = {},
                .stage = VK_SHADER_STAGE_FRAGMENT_BIT,
                .module = fragment_shader_module,
                .pName = "main",
        };

        auto const shader_stages = std::array{
                vertex_shader_stage_create_info,
                fragment_shader_stage_create_info,
        };

        struct texture_uv {
                float u, v;
        };

        auto const vertex_texture_uv_binding_description = VkVertexInputBindingDescription{
                .binding = 1,
                .stride = sizeof(texture_uv),
                .inputRate = VK_VERTEX_INPUT_RATE_VERTEX,
        };

        auto const texture_uv_attribute = VkVertexInputAttributeDescription{
                .location = 1,
                .binding = vertex_texture_uv_binding_description.binding,
                .format = VK_FORMAT_R32G32_SFLOAT,
                .offset = 0,
        };

        struct vertex_position {
                float x, y, z;
        };

        auto const vertex_position_binding_description = VkVertexInputBindingDescription{
                .binding = 0,
                .stride = sizeof(vertex_position),
                .inputRate = VK_VERTEX_INPUT_RATE_VERTEX,
        };

        auto const vertex_position_attribute = VkVertexInputAttributeDescription{
                .location = 0,
                .binding = vertex_position_binding_description.binding,
                .format = VK_FORMAT_R32G32B32_SFLOAT,
                .offset = 0,
        };

        auto const vertex_binding_dexcriptions = std::array{
                vertex_position_binding_description,
                // vertex_texture_uv_binding_description
        };
        auto const vertex_attribute_descritions = std::array{
                vertex_position_attribute,
                // texture_uv_attribute,
        };

        auto const vertex_input_info = VkPipelineVertexInputStateCreateInfo{
                .sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO,
                .pNext = nullptr,
                .flags = {},
                .vertexBindingDescriptionCount = vertex_binding_dexcriptions.size(),
                .pVertexBindingDescriptions = vertex_binding_dexcriptions.data(),
                .vertexAttributeDescriptionCount = vertex_attribute_descritions.size(),
                .pVertexAttributeDescriptions = vertex_attribute_descritions.data(),
        };

        auto const input_assembly_info = VkPipelineInputAssemblyStateCreateInfo{
                .sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO,
                .pNext = nullptr,
                .flags = {},
                .topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST,
                .primitiveRestartEnable = VK_FALSE,
        };

        state->viewport = VkViewport{
                .x = 0,
                .y = 0,
                .width = static_cast<float>(state->swapchain_extent.width),
                .height = static_cast<float>(state->swapchain_extent.height),
                .minDepth = 0,
                .maxDepth = 1,
        };

        auto const scissor = VkRect2D{
                .offset = {0, 0},
                .extent = state->swapchain_extent,
        };

        auto const viewport_state_info = VkPipelineViewportStateCreateInfo{
                .sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO,
                .pNext = nullptr,
                .flags = {},
                .viewportCount = 1,
                .pViewports = &state->viewport,
                .scissorCount = 1,
                .pScissors = &scissor,
        };

        auto const rasterizer = VkPipelineRasterizationStateCreateInfo{
                .sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO,
                .pNext = nullptr,
                .flags = {},
                .depthClampEnable = VK_FALSE,
                .rasterizerDiscardEnable = VK_FALSE,
                // .polygonMode = VK_POLYGON_MODE_POINT,
                .polygonMode = VK_POLYGON_MODE_FILL,
                // .polygonMode = VK_POLYGON_MODE_LINE,
                .cullMode = VK_CULL_MODE_BACK_BIT,
                .frontFace = VK_FRONT_FACE_CLOCKWISE,
                .depthBiasEnable = VK_FALSE,
                .lineWidth = 40,
        };

        auto const multisampling = VkPipelineMultisampleStateCreateInfo{
                .sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO,
                .pNext = nullptr,
                .flags = {},
                .rasterizationSamples = VK_SAMPLE_COUNT_1_BIT,
                .sampleShadingEnable = false,
                .minSampleShading = 1,
                .pSampleMask = nullptr,
                .alphaToCoverageEnable = VK_FALSE,
                .alphaToOneEnable = VK_FALSE,
        };

        auto const color_blend_attachment = VkPipelineColorBlendAttachmentState{
                .blendEnable = VK_FALSE,
                .srcColorBlendFactor = VK_BLEND_FACTOR_ONE,
                .dstColorBlendFactor = VK_BLEND_FACTOR_ZERO,
                .colorBlendOp = VK_BLEND_OP_ADD,
                .srcAlphaBlendFactor = VK_BLEND_FACTOR_ONE,
                .dstAlphaBlendFactor = VK_BLEND_FACTOR_ZERO,
                .alphaBlendOp = VK_BLEND_OP_ADD,
                .colorWriteMask = VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT,
        };

        auto const color_blending = VkPipelineColorBlendStateCreateInfo{
                .sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO,
                .pNext = nullptr,
                .flags = {},
                .logicOpEnable = VK_FALSE,
                .attachmentCount = 1,
                .pAttachments = &color_blend_attachment,
                .blendConstants = {0.0f},
        };

        auto const dynamic_states = std::array{
                VK_DYNAMIC_STATE_VIEWPORT,
                VK_DYNAMIC_STATE_SCISSOR,
                VK_DYNAMIC_STATE_LINE_WIDTH,
        };

        auto const dynamic_state = VkPipelineDynamicStateCreateInfo{
                .sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO,
                .pNext = nullptr,
                .flags = {},
                .dynamicStateCount = dynamic_states.size(),
                .pDynamicStates = dynamic_states.data(),
        };

        auto const depth_stencil = VkPipelineDepthStencilStateCreateInfo{
                .sType = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO,
                .pNext = nullptr,
                .flags = {},
                .depthTestEnable = VK_TRUE,
                .depthWriteEnable = VK_TRUE,
                .depthCompareOp = VK_COMPARE_OP_LESS,
                .depthBoundsTestEnable = VK_FALSE,
                .stencilTestEnable = VK_FALSE,
                .front = {},
                .back = {},
                .minDepthBounds = 0,
                .maxDepthBounds = 1,
        };

        auto const ubo_binding = VkDescriptorSetLayoutBinding{
                .binding = 0,
                .descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
                .descriptorCount = 1,
                .stageFlags = VK_SHADER_STAGE_VERTEX_BIT,
                .pImmutableSamplers = nullptr,
        };

        auto const sampler_binding = VkDescriptorSetLayoutBinding{
                .binding = 1,
                .descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER,
                .descriptorCount = 0,
                .stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT,
                .pImmutableSamplers = nullptr,
        };

        auto const descriptor_set_bindings = std::array{
                ubo_binding,
                // sampler_binding,
        };

        auto const descriptor_set_info = VkDescriptorSetLayoutCreateInfo{
                .sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO,
                .pNext = nullptr,
                .flags = {},
                .bindingCount = descriptor_set_bindings.size(),
                .pBindings = descriptor_set_bindings.data(),
        };

        VkDescriptorSetLayout descriptor_set_layout;
        if (vkCreateDescriptorSetLayout(state->device, &descriptor_set_info, state->vulkan_allocator, &descriptor_set_layout) not_eq VK_SUCCESS) {
                std::puts("unable to create descriptor set layout");
                std::exit(1);
        }

        auto const ubo_push_constant_range = VkPushConstantRange{
                .stageFlags = VK_SHADER_STAGE_VERTEX_BIT,
                .offset = 0,
                .size = sizeof(Ubo),
        };

        auto const pipeline_layout_info = VkPipelineLayoutCreateInfo{
                .sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO,
                .pNext = nullptr,
                .flags = {},
                .setLayoutCount = 1,
                .pSetLayouts = &descriptor_set_layout,
                .pushConstantRangeCount = 1,
                .pPushConstantRanges = &ubo_push_constant_range,

        };

        if (vkCreatePipelineLayout(state->device, &pipeline_layout_info, state->vulkan_allocator, &state->pipeline_layout) not_eq VK_SUCCESS) {
                std::puts("unable to create pipeline layout");
                std::exit(1);
        }

        auto const pipeline_create_info = VkGraphicsPipelineCreateInfo{
                .sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO,
                .pNext = nullptr,
                .flags = {},
                .stageCount = shader_stages.size(),
                .pStages = shader_stages.data(),
                .pVertexInputState = &vertex_input_info,
                .pInputAssemblyState = &input_assembly_info,
                .pViewportState = &viewport_state_info,
                .pRasterizationState = &rasterizer,
                .pMultisampleState = &multisampling,
                .pColorBlendState = &color_blending,
                .pDynamicState = &dynamic_state,
                .layout = state->pipeline_layout,
                .renderPass = state->render_pass,
        };

        std::puts("making graphics pipeline");
        if (vkCreateGraphicsPipelines(state->device, nullptr, 1, &pipeline_create_info, state->vulkan_allocator, &state->graphics_pipeline) not_eq VK_SUCCESS) {
                std::puts("unable to create graphics pipelines.");
                std::exit(89888);
        }

        VkPhysicalDeviceMemoryProperties physical_device_memory_properties;
        state->instance_functions.vkGetPhysicalDeviceMemoryProperties(state->physical_device, &physical_device_memory_properties);
        auto const find_memory_type = [&physical_device_memory_properties](uint32_t memory_bits_requirement, VkMemoryPropertyFlags properties) noexcept {
                for (uint32_t memory_type_index = 0; memory_type_index < physical_device_memory_properties.memoryTypeCount; ++memory_type_index) {
                        auto memory_properties = physical_device_memory_properties.memoryTypes[memory_type_index];
                        if (memory_bits_requirement & (1 << memory_type_index) and (memory_properties.propertyFlags & properties) == properties) {
                                return memory_type_index;
                        }
                }

                std::puts("unable to find suitable memory index.");
                std::terminate();
        };

        auto const create_image = [&](VkFormat format, uint32_t mip_levels, VkImageTiling tiling, VkImageUsageFlags usage) {
                auto const image_info = VkImageCreateInfo{
                        .sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO,
                        .imageType = VK_IMAGE_TYPE_2D,
                        .format = format,
                        .extent = VkExtent3D{static_cast<uint32_t>(window_width), static_cast<uint32_t>(window_height), 1},
                        .mipLevels = mip_levels,
                        .arrayLayers = 1,
                        .samples = VK_SAMPLE_COUNT_1_BIT,
                        .tiling = tiling,
                        .usage = usage,
                        .queueFamilyIndexCount = 0,
                        .pQueueFamilyIndices = nullptr,
                        .initialLayout = VK_IMAGE_LAYOUT_UNDEFINED,
                };
                VkImage image;
                if (vkCreateImage(state->device, &image_info, state->vulkan_allocator, &image) not_eq VK_SUCCESS) {
                        std::puts("unable to create vulkan image");
                        std::exit(420);
                }
                VkMemoryRequirements image_memory_requirements;
                vkGetImageMemoryRequirements(state->device, image, &image_memory_requirements);

                VkMemoryAllocateInfo memory_allocate_info{
                        .allocationSize = image_memory_requirements.size,
                        // TODO: check memory type exists.
                        .memoryTypeIndex = image_memory_requirements.memoryTypeBits,
                };

                VkDeviceMemory image_memory;
                if (vkAllocateMemory(state->device, &memory_allocate_info, state->vulkan_allocator, &image_memory) not_eq VK_SUCCESS) {
                        std::puts("unable to allocate memory for an image");
                        std::exit(420);
                }

                if (vkBindImageMemory(state->device, image, image_memory, 0) not_eq VK_SUCCESS) {
                        std::exit(420);
                }

                struct {
                        VkImage image;
                        VkDeviceMemory memory;
                } image_stuff{image, image_memory};
                return image_stuff;
        };

        // auto [depth_image, depth_image_memory] = create_image(depth_format.value(),
        // 1, VK_IMAGE_TILING_OPTIMAL, VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT);

        // auto const depth_subresource_range = VkImageSubresourceRange{
        //         .aspectMask = VkImageAspectFlagBits::VK_IMAGE_ASPECT_DEPTH_BIT,
        //         .baseMipLevel = 0,
        //         .levelCount = 1,
        //         .baseArrayLayer = 0,
        //         .layerCount = 1,
        // };
        // auto const depth_image_view_create_info = VkImageViewCreateInfo{
        //         .sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO,
        //         .pNext = nullptr,
        //         .flags = {},
        //         .image = depth_image,
        //         .viewType = VK_IMAGE_VIEW_TYPE_2D,
        //         .format = surface_format.format,
        //         .components = {},
        //         .subresourceRange = depth_subresource_range,
        // };
        // VkImageView depth_image_view;
        // if (create_image_views(device, &depth_image_view_create_info,
        // state->allocator, &depth_image_view) not_eq VK_SUCCESS) {
        //         std::exit(520);
        // }

        state->frame_buffers = state->allocator.allocate_object<VkFramebuffer>(state->swapchain_image_count);
        for (auto i = 0; i < state->swapchain_image_count; ++i) {
                auto const attachments = std::array{
                        // depth_image_view,
                        swapchain_image_views[i],
                };

                auto const creat_info = VkFramebufferCreateInfo{
                        .sType = VkStructureType::VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO,
                        .flags = {},
                        .renderPass = state->render_pass,
                        .attachmentCount = attachments.size(),
                        .pAttachments = attachments.data(),
                        .width = state->swapchain_extent.width,
                        .height = state->swapchain_extent.height,
                        .layers = 1,
                };
                if (vkCreateFramebuffer(state->device, &creat_info, state->vulkan_allocator, &state->frame_buffers[i]) not_eq VK_SUCCESS) {
                        exit(630);
                }
        }

        if (not vkCreateCommandPool) {
                std::exit(30);
        }
        VkCommandPool command_pool;
        auto const command_pool_create_info = VkCommandPoolCreateInfo{
                .sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO,
                .flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT,
                .queueFamilyIndex = static_cast<uint32_t>(graphics_index),
        };
        if (vkCreateCommandPool(state->device, &command_pool_create_info, state->vulkan_allocator, &command_pool) not_eq VK_SUCCESS) {
                std::puts("unable to create command pool.");
                std::exit(40202);
        }

        // Buffers.

        auto const create_buffer = [&](VkBufferUsageFlags usage, VkMemoryPropertyFlags memory_properties, VkDeviceSize size, VkBuffer *buffer, VkDeviceMemory *buffer_memory) noexcept {
                auto const buffer_create_info = VkBufferCreateInfo{
                        .sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
                        .size = size,
                        .usage = usage,
                        .sharingMode = VK_SHARING_MODE_EXCLUSIVE,
                };
                vkCreateBuffer(state->device, &buffer_create_info, state->vulkan_allocator, buffer);

                VkMemoryRequirements buffer_memory_requirements;
                vkGetBufferMemoryRequirements(state->device, *buffer, &buffer_memory_requirements);

                auto const buffer_memory_alloc_info = VkMemoryAllocateInfo{
                        .sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,
                        .allocationSize = buffer_memory_requirements.size,
                        .memoryTypeIndex = find_memory_type(buffer_memory_requirements.memoryTypeBits, memory_properties),
                };
                vkAllocateMemory(state->device, &buffer_memory_alloc_info, state->vulkan_allocator, buffer_memory);
                vkBindBufferMemory(state->device, *buffer, *buffer_memory, 0);
        };

        auto const buffer_copy = [&](VkBuffer src_buffer, VkBuffer dst_buffer, VkDeviceSize size) {
                auto const command_buffer_allocate_info = VkCommandBufferAllocateInfo{
                        .sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
                        .commandPool = command_pool,
                        .level = VkCommandBufferLevel::VK_COMMAND_BUFFER_LEVEL_PRIMARY,
                        .commandBufferCount = 1,
                };
                VkCommandBuffer copy_command_buffer;
                if (vkAllocateCommandBuffers(state->device, &command_buffer_allocate_info, &copy_command_buffer) not_eq VK_SUCCESS) {
                        std::puts("unable to allocate command buffers");
                        std::exit(420);
                }

                auto const begin_info = VkCommandBufferBeginInfo{.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO};

                vkBeginCommandBuffer(copy_command_buffer, &begin_info);

                auto region = VkBufferCopy{.size = size};
                vkCmdCopyBuffer(copy_command_buffer, src_buffer, dst_buffer, 1, &region);

                vkEndCommandBuffer(copy_command_buffer);

                auto submit_info = VkSubmitInfo{
                        .sType = VK_STRUCTURE_TYPE_SUBMIT_INFO,
                        .commandBufferCount = 1,
                        .pCommandBuffers = &copy_command_buffer,
                };

                vkQueueSubmit(state->graphics_queue, 1, &submit_info, nullptr);
                vkDeviceWaitIdle(state->device);
        };

        auto const stage_and_copy_buffer = [create_buffer, buffer_copy, vkMapMemory, vkUnmapMemory, state]<typename T>(std::vector<T> data, VkBufferUsageFlags usage) {
                auto const buffer_size = data.size() * sizeof(T);
                VkDeviceMemory staging_memory;
                VkBuffer staging_buffer;
                create_buffer(VK_BUFFER_USAGE_TRANSFER_SRC_BIT | usage, VK_MEMORY_PROPERTY_HOST_COHERENT_BIT | VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT, buffer_size, &staging_buffer, &staging_memory);

                void *buffer_data_staging_memory;
                vkMapMemory(state->device, staging_memory, 0, buffer_size, 0, &buffer_data_staging_memory);
                std::memcpy(buffer_data_staging_memory, data.data(), buffer_size);
                vkUnmapMemory(state->device, staging_memory);

                VkDeviceMemory buffer_memory;
                VkBuffer buffer;
                create_buffer(VK_BUFFER_USAGE_TRANSFER_DST_BIT | usage, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, buffer_size, &buffer, &buffer_memory);
                buffer_copy(staging_buffer, buffer, buffer_size);

                struct {
                        VkDeviceMemory memory;
                        VkBuffer buffer;
                } buffer_handle_and_memory{buffer_memory, buffer};
                return buffer_handle_and_memory;
        };

        auto [vertices, indices] = create_icosphere(1);

        // auto vertices = std::vector<vertex_position>{
        //         vertex_position{.9, .9, 0},
        //         vertex_position{-.9, .9, 0},
        //         vertex_position{.9, -.9, 0},
        //         vertex_position{-.9, -.9, 0},
        // };
        // auto vertices = std::vector(ico_vertices, ico_vertices+ 12);
        auto const [vertex_memory, vertex_buffer] = stage_and_copy_buffer(vertices, VK_BUFFER_USAGE_VERTEX_BUFFER_BIT);
        state->vertex_buffer = vertex_buffer;
        state->vertex_buffer_memory = vertex_memory;

        // auto indices = std::vector<uint32_t>{2, 1, 3, 0, 1, 2};
        // auto indices = std::vector(ico_indices, ico_indices+60);
        auto const [index_memory, index_buffer] = stage_and_copy_buffer(indices, VK_BUFFER_USAGE_INDEX_BUFFER_BIT);
        state->index_count = indices.size();
        state->index_buffer = index_buffer;
        state->index_buffer_memory = index_memory;

        auto const ubo_buffer_size = sizeof(Ubo);
        VkBuffer staging_ubo_buffer;
        create_buffer(VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT, VK_MEMORY_PROPERTY_HOST_COHERENT_BIT | VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT, ubo_buffer_size, &state->ubo_buffer, &state->ubo_memory);
        state->device_functions.vkMapMemory(state->device, state->ubo_memory, 0, ubo_buffer_size, 0, &state->ubo_mapped_memory);
        memcpy(state->ubo_mapped_memory, &state->ubo, ubo_buffer_size);

        auto const uniform_descriptor_pool_size = VkDescriptorPoolSize{.type = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, .descriptorCount = max_frames_in_flieght};
        auto const uniform_descriptor_pool_create_info = VkDescriptorPoolCreateInfo{
                .sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO,
                .maxSets = max_frames_in_flieght,
                .poolSizeCount = 1,
                .pPoolSizes = &uniform_descriptor_pool_size,
        };

        VkDescriptorPool uniform_descriptor_pool;
        if (auto const result = state->device_functions.vkCreateDescriptorPool(state->device, &uniform_descriptor_pool_create_info, state->vulkan_allocator, &uniform_descriptor_pool); result not_eq VK_SUCCESS) {
                puts(std::format("unable to create descriptor pool {}", string_VkResult(result)).c_str());
                exit(429);
        }

        auto const descripotor_set_allocaiton_info = VkDescriptorSetAllocateInfo{
                .sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO,
                .descriptorPool = uniform_descriptor_pool,
                .descriptorSetCount = 1,
                .pSetLayouts = &descriptor_set_layout,
        };

        if (auto const result = state->device_functions.vkAllocateDescriptorSets(state->device, &descripotor_set_allocaiton_info, &state->uniform_descriptor_set); result not_eq VK_SUCCESS) {
                puts(std::format("unable to allocate descriptor sets {}", string_VkResult(result)).c_str());
                exit(420);
        }

        auto const uniform_buffer_info = VkDescriptorBufferInfo{
                .buffer = state->ubo_buffer,
                .offset = 0,
                .range = ubo_buffer_size,
        };

        auto const write_descriptor = VkWriteDescriptorSet{
                .sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET,
                .dstSet = state->uniform_descriptor_set,
                .dstBinding = 0,
                .dstArrayElement = 0,
                .descriptorCount = 1,
                .descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
                .pImageInfo = nullptr,
                .pBufferInfo = &uniform_buffer_info,
                .pTexelBufferView = nullptr,
        };

        state->device_functions.vkUpdateDescriptorSets(state->device, 1, &write_descriptor, 0, nullptr);

        auto const command_buffer_allocate_info = VkCommandBufferAllocateInfo{
                .sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO,
                .commandPool = command_pool,
                .level = VkCommandBufferLevel::VK_COMMAND_BUFFER_LEVEL_PRIMARY,
                .commandBufferCount = static_cast<uint32_t>(state->swapchain_image_count),
        };

        state->command_buffers = state->allocator.allocate_object<VkCommandBuffer>(state->swapchain_image_count);
        if (vkAllocateCommandBuffers(state->device, &command_buffer_allocate_info, state->command_buffers) not_eq VK_SUCCESS) {
                std::puts("unable to allocate command buffers");
                std::exit(420);
        }

        for (auto i = 0; i < state->swapchain_image_count; ++i) {
                auto const &command_buffer = state->command_buffers[i];
                auto const &frame_buffer = state->frame_buffers[i];
        }

        auto current_frame = 0;
        state->image_available_semaphores = state->allocator.allocate_object<VkSemaphore>(state->swapchain_image_count);
        state->render_finished_semaphores = state->allocator.allocate_object<VkSemaphore>(state->swapchain_image_count);
        state->image_in_flieght_fences = state->allocator.allocate_object<VkFence>(state->swapchain_image_count);
        for (auto i = 0; i < max_frames_in_flieght; ++i) {
                auto empty_semaphore_create_info = VkSemaphoreCreateInfo{
                        .sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO,
                };
                if (vkCreateSemaphore(state->device, &empty_semaphore_create_info, state->vulkan_allocator, &state->image_available_semaphores[i]) not_eq VK_SUCCESS)
                        std::exit(3939);
                if (vkCreateSemaphore(state->device, &empty_semaphore_create_info, state->vulkan_allocator, &state->render_finished_semaphores[i]) not_eq VK_SUCCESS)
                        std::exit(3939);
                auto fence_create_info = VkFenceCreateInfo{
                        .sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO,
                        .flags = VkFenceCreateFlagBits::VK_FENCE_CREATE_SIGNALED_BIT,
                };
                if (vkCreateFence(state->device, &fence_create_info, state->vulkan_allocator, &state->image_in_flieght_fences[i]) not_eq VK_SUCCESS){
                        std::exit(765987);
                }
        }

        std::puts(std::format(" present index = {}", present_index).c_str());
        vkGetDeviceQueue(state->device, present_index, 0, &state->present_queue);
        state->device_functions.vkDeviceWaitIdle(state->device);
}

void record_command_buffers(Render_State const *state, u32 swapchain_image_index) {
        auto const clear_values = std::array{
                VkClearValue{.color = VkClearColorValue{.float32 = {1, 0, 1, 0}}},
                VkClearValue{.depthStencil = VkClearDepthStencilValue{.depth = 1, .stencil = 0}},
        };
        auto const viewport_scissor = VkRect2D{
                .offset = {0, 0},
                .extent = state->swapchain_extent,
        };

        auto &command_buffer = state->command_buffers[swapchain_image_index];
        auto &frame_buffer = state->frame_buffers[swapchain_image_index];

        auto const command_buffer_begin_info = VkCommandBufferBeginInfo{
                .sType = VkStructureType::VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO,
        };

        state->device_functions.vkBeginCommandBuffer(command_buffer, &command_buffer_begin_info);

        auto const render_pass_begin_info = VkRenderPassBeginInfo{
                .sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO,
                .renderPass = state->render_pass,
                .framebuffer = frame_buffer,
                .renderArea = VkRect2D{.offset{0, 0}, .extent = state->swapchain_extent},
                .clearValueCount = clear_values.size(),
                .pClearValues = clear_values.data(),
        };
        state->device_functions.vkCmdBeginRenderPass(command_buffer, &render_pass_begin_info, VkSubpassContents::VK_SUBPASS_CONTENTS_INLINE);

        state->device_functions.vkCmdSetViewport(command_buffer, 0, 1, &state->viewport);
        state->device_functions.vkCmdSetScissor(command_buffer, 0, 1, &viewport_scissor);
        state->device_functions.vkCmdBindPipeline(command_buffer, VK_PIPELINE_BIND_POINT_GRAPHICS, state->graphics_pipeline);

        VkDeviceSize offsets = 0;
        state->device_functions.vkCmdBindVertexBuffers(command_buffer, 0, 1, &state->vertex_buffer, &offsets);
        state->device_functions.vkCmdBindIndexBuffer(command_buffer, state->index_buffer, 0, VkIndexType::VK_INDEX_TYPE_UINT32);

        state->device_functions.vkCmdBindDescriptorSets(command_buffer, VkPipelineBindPoint::VK_PIPELINE_BIND_POINT_GRAPHICS, state->pipeline_layout, 0, 1, &state->uniform_descriptor_set, 0, nullptr);
        // state->device_functions.vkCmdPushConstants(command_buffer, state->pipeline_layout, VK_SHADER_STAGE_VERTEX_BIT, 0, sizeof(Ubo), &state->ubo);

        // TODO: bind a freaking defffered draw buffer thingamajig or mesh shader drawer thingy.
        state->device_functions.vkCmdDrawIndexed(command_buffer, state->index_count, 1, 0, 0, 0);
        state->device_functions.vkCmdEndRenderPass(command_buffer);
        state->device_functions.vkEndCommandBuffer(command_buffer);
}

auto draw_frame(Render_State *state) {
        state->device_functions.vkDeviceWaitIdle(state->device);
        auto &image_in_flieght_fence = state->image_in_flieght_fences[state->current_frame];
        auto &image_available_semaphore = state->image_available_semaphores[state->current_frame];
        auto &render_finished_semaphore = state->render_finished_semaphores[state->current_frame];

        if (state->device_functions.vkWaitForFences(state->device, 1, &image_in_flieght_fence, VK_TRUE, UINT64_MAX) not_eq VK_SUCCESS) {
                std::puts("unable to wait for frame fence");
        }
        if (state->device_functions.vkResetFences(state->device, 1, &image_in_flieght_fence) not_eq VK_SUCCESS) {
                std::puts("unable to reset fence");
        }

        uint32_t swapchain_image_index;
        if (state->device_functions.vkAcquireNextImageKHR(state->device, state->swapchain, UINT64_MAX, image_available_semaphore, image_in_flieght_fence, &swapchain_image_index) not_eq VK_SUCCESS) {
                std::puts("unable to aquire next swapchian image index.");
        }

        if (state->device_functions.vkWaitForFences(state->device, 1, &image_in_flieght_fence, VK_TRUE, UINT64_MAX) not_eq VK_SUCCESS) {
                std::puts("unable to wait for frame fence");
        }
        if (state->device_functions.vkResetFences(state->device, 1, &image_in_flieght_fence) not_eq VK_SUCCESS) {
                std::puts("unable to reset fence");
        }

        VkPipelineStageFlags wait_dst_stage_mask = VkPipelineStageFlagBits::VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
        auto const submit_info = VkSubmitInfo{
                .sType = VK_STRUCTURE_TYPE_SUBMIT_INFO,
                .waitSemaphoreCount = 1,
                .pWaitSemaphores = &image_available_semaphore,
                .pWaitDstStageMask = &wait_dst_stage_mask,
                .commandBufferCount = 1,
                .pCommandBuffers = &state->command_buffers[swapchain_image_index],
                .signalSemaphoreCount = 1,
                .pSignalSemaphores = &render_finished_semaphore,
        };

        state->device_functions.vkQueueSubmit(state->graphics_queue, 1, &submit_info, image_in_flieght_fence);

        auto const present_info = VkPresentInfoKHR{
                .sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR,
                .pNext = nullptr,
                .waitSemaphoreCount = 1,
                .pWaitSemaphores = &render_finished_semaphore,
                .swapchainCount = 1,
                .pSwapchains = &state->swapchain,
                .pImageIndices = &swapchain_image_index,
        };
        if (state->device_functions.vkQueuePresentKHR(state->present_queue, &present_info) not_eq VK_SUCCESS) {
                std::puts("unable to present");
        }

        if (state->device_functions.vkQueueWaitIdle(state->present_queue) not_eq VK_SUCCESS) {
                std::puts("could not wait for some reason");
        }

        state->current_frame = (state->current_frame + 1) % max_frames_in_flieght;
};