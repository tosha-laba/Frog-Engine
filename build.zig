const std = @import("std");

pub fn build(b: *std.build.Builder) void {
    const target = b.standardTargetOptions(.{});
    const mode = b.standardReleaseOptions();

    const exe = b.addExecutable("example", "src/main.cpp");

    exe.setTarget(target);
    exe.setBuildMode(mode);

    exe.addCSourceFiles(&source_files, &[_][]const u8{});

    for (includes) |dir| {
        exe.addIncludeDir(dir);
    }

    exe.linkSystemLibrary("c");
    exe.linkSystemLibrary("c++");
    exe.linkSystemLibrary("Qt5Core");
    exe.linkSystemLibrary("Qt5Gui");
    exe.linkSystemLibrary("Qt5Multimedia");
    exe.linkSystemLibrary("Qt5Widgets");

    exe.install();

    const run_cmd = exe.run();
    run_cmd.step.dependOn(b.getInstallStep());
    if (b.args) |args| {
        run_cmd.addArgs(args);
    }

    const run_step = b.step("run", "Run the app");
    run_step.dependOn(&run_cmd.step);
}

const source_files = [_][]const u8{ 
    "src/AppComponents/AudioComponent.cpp",
    "src/AppComponents/GraphicsComponent.cpp",
    "src/AppComponents/WindowComponent.cpp",

    "src/AppTemplates/QtApp.cpp",
    "src/AppTemplates/QtAudioComponent.cpp",
    "src/AppTemplates/QtGraphicsComponent.cpp",
    "src/AppTemplates/QtNativeImage.cpp",
    "src/AppTemplates/QtNativeSound.cpp",
    "src/AppTemplates/QtWindowComponent.cpp",

    "src/Example/GameScene.cpp",
    "src/Example/LogoScene.cpp",
    "src/Example/MenuScene.cpp",
    "src/Example/PlatformerEngine.cpp",
    "src/Example/Player.cpp",
    "src/Example/Spritemap.cpp",
    "src/Example/Tilemap.cpp",

    "src/App.cpp",
    "src/Engine.cpp",
    "src/Entity.cpp",
    "src/FG.cpp",
    "src/Graphic.cpp",
    "src/Scene.cpp"
};

const includes = [_][]const u8{
    "src/",
    "src/AppComponents",
    "src/AppTemplates",
    "src/Example",
    "src/Graphics",
    "src/Utils"
};