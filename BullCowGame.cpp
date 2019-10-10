// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame();//setup game

    //PrintLine(TEXT("The Hidden Word is: %s. \nIt is %i characters long."), *HiddenWord, HiddenWord.Len());//debug line
    
    
    
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    /*if game is over: ClearScreen() and ReSetup() game
    else check player guess*/


    //check if isogram
    //check if right number of characters
    //check if it's actually a word
//any of above ask to guess again
  if(bGameOver)
  {
      ClearScreen();
      SetupGame();
  }
  else
  {   
  
   if(Input == HiddenWord)
    {
        PrintLine(TEXT("Congrats you won!"));
        EndGame();
    }
    else if(Input.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT("Please put in an 8 letter word. \n You have lost."));
        EndGame();
    }
    
  
    //check letter are in correct place
    //reduce number of lives by 1
    //check number of lives
        //if >0 
           //show number of lives
           //ask for next guess
        //otherwise
        //game over screen
                //show hiddenword
             //ask to if they want to guess again
            //gather input/quit
  }

}

void UBullCowCartridge::SetupGame()
{
    HiddenWord = TEXT("cake");//set the hiddenword or call function for a hiddenword
    Lives = 8;//set number of lives
    bGameOver = false;

    PrintLine(TEXT("Welcome to Bulls and Cows"));
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());//Magic number
    PrintLine(TEXT("Type in your guess. \nPlease enter to continue...."));//prompt player for guess
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Please press enter to Play Again!"));
   
}

