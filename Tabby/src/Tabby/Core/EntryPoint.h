#pragma once

int main(int argc, char **argv) {
    Tabby::Log::Init();
    TB_PROFILE_BEGIN_SESSION("Startup", "TabbyProfile-Startup.json");

    auto app = Tabby::CreateApplication();
    TB_PROFILE_END_SESSION();

	TB_PROFILE_BEGIN_SESSION("Runtime", "TabbyProfile-Runtime.json");
    app->Run();
    TB_PROFILE_END_SESSION();

	TB_PROFILE_BEGIN_SESSION("Startup", "TabbyProfile-Shutdown.json");
    delete app;
    TB_PROFILE_END_SESSION();
}

