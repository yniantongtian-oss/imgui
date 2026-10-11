#include "imgui.h"
#include <cassert>

int main() {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.DisplaySize = ImVec2(640, 480);
    io.DeltaTime = 1.0f / 60.0f;
    unsigned char* pixels;
    int width, height;
    io.Fonts->GetTexDataAsRGBA32(&pixels, &width, &height);
    assert(pixels && width > 0 && height > 0);
    ImGui::NewFrame();
    ImGui::Begin("Acceptance");
    ImGui::TextUnformatted("Draw data smoke test");
    ImGui::End();
    ImGui::Render();
    assert(ImGui::GetDrawData()->Valid);
    ImGui::DestroyContext();
}
