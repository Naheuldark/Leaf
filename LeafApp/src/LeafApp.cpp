#include <Leaf/Core/Application.h>
#include <Leaf/Core/EntryPoint.h>
#include <Leaf/Image/Image.h>

class ExampleLayer : public Leaf::Layer {
  public:
    void onUIRender() override {
        ImGui::Begin("Hello");
        ImGui::Button("Button");
        ImGui::End();

        ImGui::ShowDemoWindow();
    }
};

Leaf::Application* Leaf::CreateApplication(int argc, char** argv) {
    Leaf::ApplicationSpecification specification;
    specification.name = "Leaf Example";

    Leaf::Application* app = new Leaf::Application(specification);
    app->pushLayer<ExampleLayer>();
    app->setMenubarCallback([app]() {
        if (ImGui::BeginMenu("File")) {
            if (ImGui::MenuItem("Exit")) {
                app->close();
            }
            ImGui::EndMenu();
        }
    });

    return app;
}
