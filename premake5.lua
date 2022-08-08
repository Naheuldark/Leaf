---
--- Leaf Project
---

workspace "LeafApp"
	architecture "x64"

	startproject "LeafApp"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include external premake files
include "LeafExternal.lua"
include "LeafApp"