#include <vulkan/vulkan.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>
#include <cstdlib>

using namespace std;

class HelloTriangleApplication{

  const uint32_t width =  800;
  const uint32_t height = 600;
  GLFWwindow* window = nullptr;

  public:
    void run(){
      initWindow();
      initVulkan();
      mainLoop();
      cleanup();
    }
  
  private:
    void initWindow(){
      if(!glfwInit()){
        throw runtime_error("Failed to initialize GLFW");
      } 
      glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
      glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
      window = glfwCreateWindow(width, height, "Vulkan" , nullptr, nullptr);
      
      if(!window){
        glfwTerminate();
        throw runtime_error("Failed to create GLFW window");
      }
    }

    void initVulkan(){
        
    } 
  
    void mainLoop(){
      while(!glfwWindowShouldClose(window)){
        glfwPollEvents();
      }
    }
  
    void cleanup(){
      glfwDestroyWindow(window);
      glfwTerminate();
    }
};

int main(){
  HelloTriangleApplication app;

  try{
    app.run();
  }catch(const exception& e){
    cerr << e.what() << endl;
    return EXIT_FAILURE;
  }  
  return EXIT_SUCCESS;

}

