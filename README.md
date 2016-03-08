# ofxAVUI

ofxAVUI is an [openFrameworks](http://www.openframeworks.cc) add-on that enables the creation of user interfaces (UI) with integrated sound and visual feedback. Different UI elements are combined into a UI “zone”. Each zone has a sound and a sound visualisation, which respond to changes in the UI. Multiple zones can be created and added to a zone. At the moment, the add-on contains the following UI elements:
- Button
- Toggle
- Slider
- XY pad
- Empty

Multiple sound effects can be used, and UI elements can be routed to effect parameters and sound playback options. Currently, the add-on contains delay (with size and feedback) and filter (with frequency and resonance) effects. Playback speed and volume can also be used for UI feedback.

Currently there are three visualisations available (Wave, Bars, Circles), but these can be easily expandable.

# Dependencies

ofxAVUI relies on Maximilian for audio.
Link: https://github.com/micknoise/Maximilian/tree/master/openFrameworks

# Example

The example code is thoroughly commented, exemplifying the use of the different UI elements, audio effects and types of visuals. Usage of UI data outside of a zone is also exemplified.

# Acknowledgements

ofxAVUI has been conceived by Nuno Correia under the Enabling AVUIs research project, which has been recipient of a EU Marie Curie fellowship, and hosted by EAVI, Goldsmiths, University of London. It has been developed by Borut Kumperščak and Nuno Correia. It is based on AVZones iOS app and inspired by Gen.AV projects.

# Links
- Nuno Correia: http://www.nunocorreia.com
- Borut Kumperščak: http://www.wirelesscowboy.org
- EAVI, Goldsmiths, University of London: http://eavi.goldsmithsdigital.com
- AVZones: http://www.avzones.org
- Gen.AV: http://www.gen-av.org
