#pragma once

int main(int argc, char **argv) {
    Tabby::Log::Init();
    TB_CORE_WARN("Initialized Log!");
    int a = 5;
    TB_INFO("Hello! Var={0}", a);

    auto app = Tabby::CreateApplication();
    app->Run();
    delete app;
}

