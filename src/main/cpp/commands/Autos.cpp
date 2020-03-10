/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Autos.h"

// Can "decorate" commands.  eg:
// command.WithTimeout(1_s)  cancels the command after the time has elapsed
// Will be interrupted if m_limitSwitch.get() returns true.  eg, electric eyes and ball intake
// command.InterruptOn([&m_limitSwitch] { return m_limitSwitch.Get(); });

LeftAuto::LeftAuto(DriveSubsystem* drive) {
  AddCommands(
      // Drive back the specified time.  Positive power really is backwards
      DriveStraight(0.6, drive).WithTimeout(1_s),
      // turn around 180_deg.  Timeout here is in case it doesn't settle in 2s
      TurnToAngle(180_deg, drive).WithTimeout(2_s)
  );
}

RightAuto::RightAuto(DriveSubsystem* drive) {
  AddCommands(
      // Drive back the specified time.  Positive power really is backwards
      DriveStraight(0.6, drive).WithTimeout(1_s),
      // turn around 180_deg.  Timeout here is in case it doesn't settle in 2s
      TurnToAngle(90_deg, drive).WithTimeout(2_s)
  );
}
