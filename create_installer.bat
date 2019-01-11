xcopy release installer\packages\org.abt.mapapalco\data /E /Y
cd installer
binarycreator --offline-only -c config/config.xml -p packages installer