/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SetLimelightPipeline.h"

SetLimelightPipeline::SetLimelightPipeline(int pipeline,
                             DriveSubsystem* subsystem)
    : m_drive(subsystem), m_pipeline(pipeline) {
  AddRequirements({subsystem});
}

void SetLimelightPipeline::Initialize() {
  m_drive->SelectLimelightPipeline(m_pipeline);
}

// if we're killed, put back the camera
void SetLimelightPipeline::End(bool interrupted) { 
  m_drive->SelectLimelightPipeline(1);
}

// it's a state.  Run till canceled
bool SetLimelightPipeline::IsFinished() { return false; }
