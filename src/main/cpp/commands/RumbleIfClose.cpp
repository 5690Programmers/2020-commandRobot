/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/RumbleIfClose.h"

#include "Constants.h"

RumbleIfClose::RumbleIfClose(frc::XboxController* controller,
                             DriveSubsystem* subsystem)
    : m_controller(controller), m_drive(subsystem) {
// this command only reads the Distance value from the drive
// So, while it "requires" the drive to exist, we don't mind if
// it runs at the same time as other drive things.  
// So, commenting this out.
//  AddRequirements({subsystem});
}

void RumbleIfClose::Initialize() {
  if (m_drive->GetDistance() < kRumbleDistance)
    m_controller->SetRumble(frc::GenericHID::RumbleType::kLeftRumble,1.0);
  else
    m_controller->SetRumble(frc::GenericHID::RumbleType::kLeftRumble,0.0);  
}

// if we're killed, stop rumbling
void RumbleIfClose::End(bool interrupted) { 
  m_controller->SetRumble(frc::GenericHID::RumbleType::kLeftRumble,0.0);
}

// it's a state.  Run till canceled
bool RumbleIfClose::IsFinished() { return false; }
