//
// Created by Vincent on 25.03.24.
//

#include "MainWindow.h"

namespace UserEvents {
    void button1_OnClick(Forms::IControl *sender, SDL_MouseButtonEvent args) {
        auto form = (MainWindow*)sender->owner;
        std::cout << form->GraphBox->points->size() << std::endl;
    }

    void greenButton_OnClick(Forms::IControl *sender, SDL_MouseButtonEvent args) {
        auto form = (MainWindow*)sender->owner;
        form->GraphBox->currentColor = Graphics::ColorEnum::Green;
    }

    void blueButton_OnClick(Forms::IControl *sender, SDL_MouseButtonEvent args) {
        auto form = (MainWindow*)sender->owner;
        form->GraphBox->currentColor = Graphics::ColorEnum::Blue;
    }

    void redButton_OnClick(Forms::IControl *sender, SDL_MouseButtonEvent args) {
        auto form = (MainWindow*)sender->owner;
        form->GraphBox->currentColor = Graphics::ColorEnum::Red;
    }

    void whiteButton_OnClick(Forms::IControl *sender, SDL_MouseButtonEvent args) {
        auto form = (MainWindow*)sender->owner;
        form->GraphBox->currentColor = Graphics::ColorEnum::White;
    }

    void blackButton_OnClick(Forms::IControl *sender, SDL_MouseButtonEvent args) {
        auto form = (MainWindow*)sender->owner;
        form->GraphBox->currentColor = Graphics::ColorEnum::Black;
    }

    void clearButton_OnClick(Forms::IControl *sender, SDL_MouseButtonEvent args) {
        auto form = (MainWindow*)sender->owner;
        form->GraphBox->DoCleanUp();
    }

    void GraphBoxMouseMove(Forms::IControl *sender, SDL_MouseMotionEvent args) {
        //std::cout << "DONE";
        auto *sndr = dynamic_cast<GraphBoxControl*>(sender);
        if (*sndr->isMouseDown) {
            auto *pnt = new CirclePoint(args.x, args.y, sndr->currentColor);
            sndr->points->push_back(pnt);
        }
    }
}

void MainWindow::InitializeComponent() {
    Location->Fill(100, 100);
    Size->Fill(500, 400);
    *Title = "SDL Paint";

    GraphBox = new GraphBoxControl(renderer);
    GraphBox->Location->Fill(100, 0);
    GraphBox->Size->Fill(400, 400);
    GraphBox->BackgroundColor->SetColor(200,200,200,255);
    GraphBox->OnMove = &UserEvents::GraphBoxMouseMove;
    AddControl(GraphBox);

    OptionsBackground = new Forms::Rectangle(renderer);
    OptionsBackground->Location->Fill(0,0);
    OptionsBackground->Size->Fill(100, 400);
    OptionsBackground->BackgroundColor->SetColor(220,220,220,255);
    OptionsBackground->BorderStyle = BorderStyle::FixedSingle;
    OptionsBackground->ForegroundColor->SetColor(Graphics::Black);
    AddControl(OptionsBackground);

    BrushButton = new Forms::Button(renderer, textRenderer);
    BrushButton->Location->Fill(15,15);
    BrushButton->Size->Fill(70, 24);
    BrushButton->BackgroundColor->SetColor(0,255,0,255);
    BrushButton->ForegroundColor->SetColor(0,0,0,255);
    *BrushButton->AutoSize = false;
    BrushButton->TextAllign = TextAllign::MiddleCenter;
    *BrushButton->Text = "Brush";
    *BrushButton->TextSize = 15;
    BrushButton->BorderStyle = BorderStyle::FixedSingle;
    BrushButton->OnClick = &UserEvents::button1_OnClick;
    AddControl(BrushButton);

    ClearBrushButton = new Forms::Button(renderer, textRenderer);
    ClearBrushButton->Location->Fill(15,54);
    ClearBrushButton->Size->Fill(70, 24);
    ClearBrushButton->BackgroundColor->SetColor(0,255,0,255);
    ClearBrushButton->ForegroundColor->SetColor(0,0,0,255);
    *ClearBrushButton->AutoSize = false;
    ClearBrushButton->TextAllign = TextAllign::MiddleCenter;
    *ClearBrushButton->Text = "Clear";
    *ClearBrushButton->TextSize = 15;
    ClearBrushButton->BorderStyle = BorderStyle::FixedSingle;
    ClearBrushButton->OnClick = &UserEvents::clearButton_OnClick;
    AddControl(ClearBrushButton);

    GreenButton = new Forms::Button(renderer, textRenderer);
    GreenButton->Location->Fill(15, 94);
    GreenButton->Size->Fill(24, 24);
    *GreenButton->AutoSize = false;
    GreenButton->BackgroundColor->SetColor(Graphics::ColorEnum::Green);
    GreenButton->ForegroundColor->SetColor(Graphics::ColorEnum::Green);
    *GreenButton->Text = "";
    GreenButton->BorderStyle = BorderStyle::FixedSingle;
    GreenButton->OnClick = &UserEvents::greenButton_OnClick;
    AddControl(GreenButton);

    RedButton = new Forms::Button(renderer, textRenderer);
    RedButton->Location->Fill(15, 133);
    RedButton->Size->Fill(24, 24);
    *RedButton->AutoSize = false;
    RedButton->BackgroundColor->SetColor(Graphics::ColorEnum::Red);
    RedButton->ForegroundColor->SetColor(Graphics::ColorEnum::Red);
    RedButton->OnClick = &UserEvents::redButton_OnClick;
    *RedButton->Text = "";
    RedButton->BorderStyle = BorderStyle::FixedSingle;
    AddControl(RedButton);

    BlueButton = new Forms::Button(renderer, textRenderer);
    BlueButton->Location->Fill(15, 172);
    BlueButton->Size->Fill(24, 24);
    *BlueButton->AutoSize = false;
    BlueButton->BackgroundColor->SetColor(Graphics::ColorEnum::Blue);
    BlueButton->ForegroundColor->SetColor(Graphics::ColorEnum::Blue);
    BlueButton->OnClick = &UserEvents::blueButton_OnClick;
    *BlueButton->Text = "";
    BlueButton->BorderStyle = BorderStyle::FixedSingle;
    AddControl(BlueButton);

    BlackButton = new Forms::Button(renderer, textRenderer);
    BlackButton->Location->Fill(54, 94);
    BlackButton->Size->Fill(24, 24);
    *BlackButton->AutoSize = false;
    BlackButton->BackgroundColor->SetColor(Graphics::ColorEnum::Black);
    BlackButton->ForegroundColor->SetColor(Graphics::ColorEnum::Black);
    BlackButton->OnClick = &UserEvents::blackButton_OnClick;
    *BlackButton->Text = "";
    BlackButton->BorderStyle = BorderStyle::FixedSingle;
    AddControl(BlackButton);

    WhiteButton = new Forms::Button(renderer, textRenderer);
    WhiteButton->Location->Fill(54, 133);
    WhiteButton->Size->Fill(24, 24);
    *WhiteButton->AutoSize = false;
    WhiteButton->BackgroundColor->SetColor(Graphics::ColorEnum::White);
    WhiteButton->ForegroundColor->SetColor(Graphics::ColorEnum::White);
    WhiteButton->OnClick = &UserEvents::whiteButton_OnClick;
    *WhiteButton->Text = "";
    WhiteButton->BorderStyle = BorderStyle::FixedSingle;
    AddControl(WhiteButton);
}

void MainWindow::Close() {
    Forms::Form::Close();
}

