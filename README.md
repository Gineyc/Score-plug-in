# Score_VST A AI-driven plugin for video-to-audio mapping for music creation
[![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)](https://travis-ci.org/joemccann/dillinger)

The study on SCORE! plug-in is my Master's thesis design project, which is highly graded (8.0/10) [link to the thesis](https://publications.beeldengeluid.nl/pub/678/Mailin_Chen_Final_Thesis.pdf). Score! project is funded by [NWO](https://www.nwo.nl/en). As a subproject of [RE: VIVE](https://revivethis.org/) initiative, it aims to
develop an innovative music creation tool allowing the video
archives to generate audio through DL techniques. It can
improve the end-users’ accessibility to produce music as well
as lower the barriers between the audio and visual creative
expression. The back-end algorithm of SCORE! plug-in is an
unsupervised deep learning method for generating audio for a given
video.

This application is built in C++ based on [JUCE Framework]（https://juce.com/）, which can be compiled to vst2, vst3, standalone application .etc and stably running on common Digital Audio Workstation(Daws) like [Ableton](https://www.ableton.com/) and [Cubase](https://new.steinberg.net/cubase/).


The workflow of score plug-in is showing as pic:
![workflow](https://github.com/Gineyc/Score-plug-in/blob/master/img/pipeline.png?raw=true)

The interface of score plug-in is showing as follows:
![interface](https://github.com/Gineyc/Score-plug-in/blob/master/img/screencast.png?raw=true)

# Screencast
If you wanna know more about this Plug-in, please follow the link: [Link to the Screencast](https://youtu.be/VvIqDpT2mGo):
![video](https://github.com/Gineyc/Score-plug-in/blob/master/img/video.png?raw=true)



# Installation

Step1: Download score algorithm repository on: https://github.com/pbloem/score and set directory path of the repository to "D:\\Master\\REPO\\pbloem\\score\\", then configure the development environment follow the Installation guide on "score/README.md"

Step2: Download Maximillian library on: [Maximillian](https://github.com/micknoise/Maximilian)

Step3: Download and Install Projucer on: [Projucer](https://juce.com/discover/projucer)

Step3: open the "VST.jucer" with projucer, and select Visual Studio 2017 as the exporter.

Step4: Configure the Debug options of exporters: add the "pythondirectory\include" and Maximillian directory path to the "Head Search Paths". Add the "pythondirectory\libs" to the "Extra Library Search Paths"

Step5: Launch the VSstudio and "Build solutions"

Step6: Now you can find the built plugin in vst3, RTAS or Standalone application in the directory.

Step7: Paste the plugin file to your DAW's VST plugin folder and put videos you are going to generate into the directory path of score algorithm.  

Step8: Now, you are able to load the score plug-in in your DAW and generate the midi file for the videos. Enjoy~

