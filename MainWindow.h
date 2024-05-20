//
// Created by Vincent on 25.03.24.
//

#ifndef SDLFORMS_TESTFORM1_H
#define SDLFORMS_TESTFORM1_H

#pragma once;

#include "GraphBoxControl.h"
#include "Forms/Form.h"
#include "Forms/Controls.h"
#include "iostream"

class MainWindow : public Forms::Form  {
    public:
        GraphBoxControl *GraphBox;
        Forms::Button *BrushButton;
        Forms::Button *ClearBrushButton;
        Forms::Rectangle *OptionsBackground;
        Forms::Button *RedButton;
        Forms::Button *GreenButton;
        Forms::Button *BlueButton;
        Forms::Button *BlackButton;
        Forms::Button *WhiteButton;
    public:
        void InitializeComponent();

        MainWindow() : Forms::Form(){
            InitializeComponent();
            std::cout << "TestForm.h >>> Child Form Initialization completed." << std::endl;
        }

        void Close();
};




#endif //SDLFORMS_TESTFORM1_H
