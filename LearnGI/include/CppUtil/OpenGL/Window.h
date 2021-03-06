#include<string>

#define GLEW_STATIC
#include<GL/glew.h>
#include<GLFW/glfw3.h>

// friend fun
void framebuffer_size_callback(GLFWwindow* window, int width, int height);// 调整视窗大小，但帧缓冲大小并没能同步调整
void mouse_callback(class GLFWwindow* window, double xPos, double yPos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

using std::string;
namespace CppUtil {
	namespace OpenGL {
		const unsigned int DEFAULT_SCR_WIDTH = 800;
		const unsigned int DEFAULT_SCR_HEIGHT = 600;

		class Camera;
		class Window {
		public:
			Window(const unsigned int width, const unsigned int height, const char* _name, Camera* _camera);
			
			void MakeContextCurrent();

			// Window Settings
			void ProcessKeyboard(float deltaTime);
			void SetFramebufferSizeCallback(GLFWframebuffersizefun callback);// Tell GLFW we want to call this function on every window resize by registering it
			void SetInputMode(int mode, int value);
			void SetCursorPosCallback(GLFWcursorposfun callback);// Set the required callback functions
			void SetScrollCallback(GLFWscrollfun callback);
			void SetKeyCallback(GLFWkeyfun key_callback);

			GLFWwindow* GetGLFWwindow() { return this->window; }
			unsigned int GetWidth() { return this->src_width; }
			unsigned int GetHeight() { return this->src_height; }
			const float GetRatioWH()const { return this->src_width / (float)this->src_height; }
		private:
			void Load();

			bool IsValid;
			string name;
			unsigned int src_width;
			unsigned int src_height;

			Camera* camera;
			GLFWwindow* window;
			/*GLFWwindow* share;
			GLFWmonitor* monitor;*/
		};
	}
}