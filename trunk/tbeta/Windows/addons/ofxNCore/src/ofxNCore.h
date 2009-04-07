/***************************************************************************
*
 *  ofxNCore.h
 *  NUI Group Community Core Vision
 * 
 *  Created by NUI Group Dev Team A on 2/1/09.
 *  Copyright 2009 NUI Group/Inc. All rights reserved.       
*   Version : 5.21
*
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are 
* met:
* 1. Redistributions of source code must retain the above copyright
* notice, this list of conditions and the following disclaimer as
* the first lines of this file unmodified.
* 2. Redistributions in binary form must reproduce the above copyright
* notice, this list of conditions and the following disclaimer in the
* documentation and/or other materials provided with the distribution.
*
* THIS SOFTWARE IS PROVIDED BY BEN WOODHOUSE ``AS IS'' AND ANY EXPRESS OR
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL BEN WOODHOUSE BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
* NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
* THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
* THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

* Web: http://nuigroup.com
*
* (...)
*
***************************************************************************/

#ifndef OFXNCORE_H
#define OFXNCORE_H

//removes the 'x' button on windows which causes a crash due to a GLUT bug

#ifdef TARGET_WIN32
//HWND hwndConsole = FindWindowA(NULL, "tbeta");
//HMENU hMnu = ::GetSystemMenu(hwndConsole, FALSE);
//RemoveMenu(hMnu, SC_CLOSE, MF_BYCOMMAND);
#endif

#include "Events/TouchMessenger.h"

//Used for tracking algo
#include "Tracking/BlobManager.h"
#include "Tracking/tracking.h"

//GPU image filters
#include "Filters/GPUImageFilter.h"

//Used for warped image calibration
#include "Calibration/boxAlign.h"

//Used other calibration
#include "Calibration/calibrationB.h"

//Communications
#include "Communication/TUIO.h"

//GUI
#include "Controls/ofxGui.h"
#include "Controls/ofxGuiTypes.h"

//#include "Camera/Camera.h"

// Modules (Audio/Visual/Physical) Custom modules that fall in each category...
#include "Modules/ofxNCoreBase.h" // Baseline Module Elements
#include "Modules/ofxNCoreVision.h" // Extended Module for Vision Processing

#endif
