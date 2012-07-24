if not _PREMAKE_VERSION then
    os.execute('premake4 --file=premake4_makefile.lua clean')
    os.execute('premake4 --file=premake4_makefile.lua gmake')
    return
end


solution "unit_test"
    configurations { "Debug", "Release" }
 
    -- A project defines one build target
    project "unit_test"
        kind "ConsoleApp"
        language "C"
        location ( "build" )
        targetdir ( "bin" )
        libdirs { "/usr/lib" }
        links { }

        includedirs { 
                "../../deps/libsl/include", 
                "../../deps/libc/include", 
                "../../deps/cunit/include", 
                "usr/include" 
        }
        files { 
                "../../deps/libc/src/**.h", 
                "../../deps/libc/src/**.c", 
                "../../deps/libsl/src/**.h", 
                "../../deps/libsl/src/**.c", 
                "../../deps/cunit/src/**.h", 
                "../../deps/cunit/src/**.c", 
                "src/**.h", 
                "src/**.c" 
        }
 
        configuration "Debug"
            defines { "DEBUG" }
            flags { "Symbols", "ExtraWarnings" }
 
        configuration "Release"
            defines { "NDEBUG" }
            flags { "Optimize" }      
