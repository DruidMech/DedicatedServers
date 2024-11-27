﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

struct FDSRecordMatchStatsInput;
#include "CoreMinimal.h"
#include "UI/HTTP/HTTPRequestManager.h"
#include "GameStatsManager.generated.h"

/**
 * 
 */
UCLASS()
class DEDICATEDSERVERS_API UGameStatsManager : public UHTTPRequestManager
{
	GENERATED_BODY()
public:
	void RecordMatchStats(const FDSRecordMatchStatsInput& RecordMatchStatsInput);
};
