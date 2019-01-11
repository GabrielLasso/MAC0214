xcopy release installer\packages\org.abt.formacaotaiko\data /E /Y
cd installer
binarycreator --offline-only -c config/config.xml -p packages installer