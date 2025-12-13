#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BFL_GetThumbnails.generated.h"

UCLASS()
class GET_THUMBNAILS_API UBFL_GetThumbnails : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable)
	static void SaveThumbnail(const FAssetData& AssetData);

	UFUNCTION(BlueprintCallable)
	static void BeginBackgroundRemoval();
};
