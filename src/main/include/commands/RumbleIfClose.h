/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/XboxController.h>

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/DriveSubsystem.h"

class RumbleIfClose
    : public frc2::CommandHelper<frc2::CommandBase, RumbleIfClose> {
 public:
  /**
   * Creates a new RumbleIfClose.
   *
   * @param controller the xbox controller to rumble
   * @param drive The drive subsystem on which this command will run
   */
  RumbleIfClose(frc::XboxController* controller, DriveSubsystem* subsystem);

  void Initialize() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  DriveSubsystem* m_drive;
  frc::XboxController* m_controller;
};
