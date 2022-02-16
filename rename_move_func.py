import subprocess

table = """ft_OnItemRelease:
.4byte ftMario_OnItemRelease
.4byte ftFox_OnItemRelease
.4byte ftCFalcon_OnItemRelease
.4byte ftDonkey_OnItemRelease
.4byte ftKirby_OnItemRelease
.4byte ftKoopa_OnItemRelease
.4byte ftLink_OnItemRelease
.4byte ftSeak_OnItemRelease
.4byte ftNess_OnItemRelease
.4byte ftPeach_OnItemRelease
.4byte ftIceClimber_OnItemRelease
.4byte ftIceClimber_OnItemRelease
.4byte ftPikachu_OnItemRelease
.4byte ftSamus_OnItemRelease
.4byte ftYoshi_OnItemRelease
.4byte ftPurin_OnItemRelease
.4byte ftMewtwo_OnItemRelease
.4byte ftLuigi_OnItemRelease
.4byte ftMars_OnItemRelease
.4byte ftZelda_OnItemRelease
.4byte ftCLint_OnItemRelease
.4byte ftDrMario_OnItemRelease
.4byte ftFalco_OnItemRelease
.4byte ftPichu_OnItemRelease
.4byte ftGameWatch_OnItemRelease
.4byte ftGanon_OnItemRelease
.4byte ftRoy_OnItemRelease
.4byte NULL
.4byte NULL
.4byte ftZakoBoy_OnItemRelease
.4byte ftZakoGirl_OnItemRelease
.4byte ftGKoopa_OnItemRelease
.4byte NULL"""

lines = table.split('\n')

move_name = lines[0].split("_")[1][:-1]
print(move_name)

fighters = [
    "ftMario",
    "ftFox",
    "ftCFalcon",
    "ftDonkey",
    "ftKirby",
    "ftKoopa",
    "ftLink",
    "ftSeak",
    "ftNess",
    "ftPeach",
    "ftIceClimber",
    "ftNana",
    "ftPikachu",
    "ftSamus",
    "ftYoshi",
    "ftPurin",
    "ftMewtwo",
    "ftLuigi",
    "ftMars",
    "ftZelda",
    "ftCLint",
    "ftDrMario",
    "ftFalco",
    "ftPichu",
    "ftGameWatch",
    "ftGanon",
    "ftRoy",
    "ftMasterhand",
    "ftCrazyhand",
    "ftZakoBoy",
    "ftZakoGirl",
    "ftGKoopa",
    "ftSandbag",
]

for i in range(len(lines[1:])):
  line = lines[i+1]
  func = line.split(" ")[1]

  if func == "NULL":
    continue

  new_name = fighters[i] + "_" + move_name
  print(f'rg "{func}" --files-with-matches  | xargs sed -i "s/{func}/{new_name}/g"')

  subprocess.call(f'rg "${func}" --files-with-matches | xargs sed -i "s/{func}/{new_name}/g"', shell=True)
