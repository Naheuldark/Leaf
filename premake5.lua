---
--- Leaf Project
---

include "./dependencies.lua"

workspace "Leaf"
	architecture "x64"

	startproject "LeafApp"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include external premake files
group "Dependencies"
	include "vendor/GLFW"
	include "vendor/imgui"
group ""

group "Core"
	include "Leaf"
group ""

include "LeafApp"