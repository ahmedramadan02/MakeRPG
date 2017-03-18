// MakeRPG.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Main.h"

int main(int argc, char* argv[])
{
	CMain main(700,600);
	main.GameLoop();

	return 0;
}

