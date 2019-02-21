// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioUE4Plugin.h"
#include "Schemas/FModioResponse.h"
#include "Schemas/FModioUser.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "UGetAuthenticatedUserCallbackProxy.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FGetAuthenticatedUserCheckResult,
    FModioResponse,
    response,
    FModioUser,
    user);

UCLASS()
class MODIO_API UGetAuthenticatedUserCallbackProxy : public UOnlineBlueprintCallProxyBase
{
  GENERATED_UCLASS_BODY()

  UPROPERTY(BlueprintAssignable)
  FGetAuthenticatedUserCheckResult OnSuccess;

  UPROPERTY(BlueprintAssignable)
  FGetAuthenticatedUserCheckResult OnFailure;

  UFUNCTION(BlueprintCallable, Category = "mod.io", meta = (BlueprintInternalUseOnly = "true"))
  static UGetAuthenticatedUserCallbackProxy *GetAuthenticatedUser();

  virtual void Activate() override;

  void OnGetAuthenticatedUserDelegate(FModioResponse Response, FModioUser User);
};