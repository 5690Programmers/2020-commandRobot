/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ShooterShoot.h"

ShooterShoot::ShooterShoot(ShooterSubsystem* subsystem) : m_shooter(subsystem) {
  AddRequirements({subsystem});
}

void ShooterShoot::Initialize() { m_shooter->Shoot(); }

// this is a state, it lasts till it's cancelled
// although we could check if we are at the right RPM
bool ShooterShoot::IsFinished() { return false; }
