#pragma once

#include "../../Core/Core.h"
#include "../../Window.h"

#include <GLFW/glfw3.h>

namespace Stellara {

	class STELLARA_API WindowsWindow : public Window {
	
		public:
			WindowsWindow(const WindowProps& props);
			virtual ~WindowsWindow();

			void OnUpdate() override;

			unsigned int GetWidth() const override { return m_Data.Width; }
			unsigned int GetHeight() const override { return m_Data.Height; }
			
			void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
			void SetVSync(bool enabled) override;
			bool IsVSync() const override;
			
			inline virtual void* GetNativeWindow() const { return m_Window; }
		private:
			virtual void Init(const WindowProps& props);
			virtual void Shutdown();
		private:
			GLFWwindow* m_Window;

			struct WindowData {

				std::string Title;
				unsigned int Width, Height;
				bool VSync;

				EventCallbackFn EventCallback;
			};

			WindowData m_Data;
	};
}