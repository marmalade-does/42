



import argparse

parser = argparse.ArgumentParser(description="things are cool")
parser.add_argument('--celsiu', type = int, required = True, description = 'int type tmperature in celsius')
parser.parse_args()
cel = parser.celsius






