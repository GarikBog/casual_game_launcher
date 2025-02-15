#ifndef LAUNCHER
#include "launcher.hpp"
#define LAUNCHER
#endif // !LAUNCHER


GameLauncher::GameLauncher(unsigned int height)
{
	window_height = height;
	window_width = window_height * 0.85;


	background = new Object({ 0,0 }, { 1500,1750 }, { window_width,window_height }, "ADD TEXTURE ");

	previous_button = new PreviousPageButton({ window_width / 175,window_height / 3.75 },
		{ 700,258 },
		{ window_width / 6.78,window_height / 3.75 },
		"ADD TEXTURE!!!", log);

	next_button = new NextPageButton({ window_width - window_width / 175 - window_width / 6.78,window_height / 3.75 },
		{ 700,258 },
		{ window_width / 6.78,window_height / 3.75 },
		"ADD TEXTURE !!!", log);

	close = new CloseButton({window_width - window_width/50 - window_width / 8.75,window_height/30},
		{ 200,200 },
		{ window_width / 8.75,window_width / 7.5 },
		"ADD TEXTURE!!!", log);
}
