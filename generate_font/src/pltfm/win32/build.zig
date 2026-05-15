const std = @import("std");



const app_name = "generate_font";

const root_dir = "../../../..";
const app_root = root_dir ++ "/generate_font/src";

const main_cpp = app_root ++ "/generate_main.cpp";


const cpp_flags = &[_][]const u8{
    "-std=c++23",
    //"-mavx",
    //"-mavx2",
    //"-mfma",
    //"-DNDEBUG",
    //"-O3",
};

const inc_paths = &[_][]const u8{
    //inc_all,
};

const lib_paths = &[_][]const u8{
    //lib_all,
};

const cpp_libs = &[_][]const u8{    
    //"pthread",
    //"tbb"
};


pub fn build(b: *std.Build) void 
{
    const optimize = b.option(std.builtin.OptimizeMode, "optimize", "Optimization mode") orelse .Debug;
    //const optimize = b.option(std.builtin.OptimizeMode, "optimize", "Optimization mode") orelse .ReleaseFast;

    const target = b.graph.host; // run from Windows
    //const target = b.resolveTargetQuery(.{ .cpu_arch = .x86_64, .os_tag = .windows });

    const exe = b.addExecutable(.{
        .name = app_name,
        .root_module = b.createModule(.{
            .root_source_file = null,
            .target = target,
            .optimize = optimize,
            .link_libc = true,
            .link_libcpp = true,
        }),
    });

    exe.subsystem = .Windows;

    exe.root_module.addCSourceFiles(.{
        .files = &.{
            main_cpp,
        },
        .flags = cpp_flags,
    });

    for (cpp_libs) |lib|
    {
        exe.root_module.linkSystemLibrary(lib, .{});
    }
    

    // zig build run
    const run_step = b.step("run", "Run");
    const run_cmd = b.addRunArtifact(exe);
    if (b.args) |args| run_cmd.addArgs(args);
    run_step.dependOn(&run_cmd.step);    
}

// zig build -Doptimize=Debug          # full debug symbols, no -O3, assertions on
// zig build -Doptimize=ReleaseSafe    # safe release (keeps bounds checks)
// zig build -Doptimize=ReleaseFast    # your current -O3 mode (default above)