#include <vulkan/vulkan.h>
#include <stdio.h>
#include <inttypes.h>

#define nullptr ((void*)0)
#define PHYS_COUNT_MAX (255)

int main(void) {
	VkResult result = VK_SUCCESS;
	VkApplicationInfo appInfo = {
		.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
		.pApplicationName = "Miksi First Demo",
		.applicationVersion = 1,
		.apiVersion = VK_MAKE_VERSION(1, 0, 0),
	};

	VkInstanceCreateInfo instanceCreateInfo = {
		.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
		.pApplicationInfo = &appInfo,
	};

	VkInstance instance = 0;
	result = vkCreateInstance(&instanceCreateInfo, nullptr, &instance);

	if (result == VK_SUCCESS) {
		VkPhysicalDevice physDevs[PHYS_COUNT_MAX] = {0};
		uint32_t physDevCount = 0;

		result = vkEnumeratePhysicalDevices(instance, &physDevCount, physDevs);
		printf("result: %u, nDevices: %u\n", result, physDevCount);

		for (uint32_t i = 0; i < physDevCount; i+=1) {
			VkPhysicalDeviceProperties props = {0};
			vkGetPhysicalDeviceProperties(physDevs[i], &props);

			printf("device #: %u %s\n", i, props.deviceName);
			printf("\t Api: %u.%u.%u\n", VK_VERSION_MAJOR(props.apiVersion),
										 VK_VERSION_MINOR(props.apiVersion),
										 VK_VERSION_PATCH(props.apiVersion));
			printf("\t Driver: %u\n", props.driverVersion);
			printf("\t vendor id: 0x%x\n", props.vendorID);
			printf("\t device id: 0x%x\n", props.deviceID);
		}
	}

	return 0;
}
