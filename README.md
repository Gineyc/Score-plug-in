# Score_VST

Plug-in for video-to-audio mapping
Currently ONLY support Windows

Installation

Step1: Download score algorithm repository on: https://github.com/pbloem/score and set directory path of the repository to "D:\\Master\\REPO\\pbloem\\score\\", then configure the development environment follow the Installation guide on "score/README.md"

Step2: Download Maximillian library on: https://github.com/micknoise/Maximilian

Step3: Download and Install Projucer on: https://juce.com/discover/projucer

Step3: open the "VST.jucer" with projucer, and select Visual Studio 2017 as the exporter.

Step4: Configure the Debug options of exporters: add the "pythondirectory\include" and Maximillian directory path to the "Head Search Paths". Add the "pythondirectory\libs" to the "Extra Library Search Paths"

Step5: Launch the VSstudio and "Build solutions"

Step6: Now you can find the built plugin in vst3, RTAS or Standalone application in the directory.

Step7: Paste the plugin file to your DAW's VST plugin folder and put videos you are going to generate into the directory path of score algorithm.  

Step8: Now, you are able to load the score plug-in in your DAW and generate the midi file for the videos. Enjoy~
