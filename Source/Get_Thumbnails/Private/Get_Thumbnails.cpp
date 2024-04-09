// Copyright Epic Games, Inc. All Rights Reserved.

#include "Get_Thumbnails.h"

#define LOCTEXT_NAMESPACE "FGet_ThumbnailsModule"

void FGet_ThumbnailsModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FGet_ThumbnailsModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FGet_ThumbnailsModule, Get_Thumbnails)