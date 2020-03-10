/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/DriveSubsystem.h"

class SetLimelightPipeline
    : public frc2::CommandHelper<frc2::CommandBase, SetLimelightPipeline> {
 public:
  /**
   * Creates a new SetLimelightPipeline.
   *
   * @param pipeline Which pipeline to use: 0 = targetting, 1 = camera
   * @param drive The drive subsystem on which this command will run
   */
  SetLimelightPipeline(int pipeline, DriveSubsystem* subsystem);

  void Initialize() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  DriveSubsystem* m_drive;
  int m_pipeline;
};
