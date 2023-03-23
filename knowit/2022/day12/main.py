from pprint import pprint
from PIL import Image
import piexif, os
from matplotlib import pyplot as plt

codec = 'ISO-8859-1'  # or latin-1

def exif_to_tag(exif_dict):
    exif_tag_dict = {}
    thumbnail = exif_dict.pop('thumbnail')
    #exif_tag_dict['thumbnail'] = thumbnail.decode(codec)

    for ifd in exif_dict:
        exif_tag_dict[ifd] = {}
        for tag in exif_dict[ifd]:
            try:
                element = exif_dict[ifd][tag].decode(codec)

            except AttributeError:
                element = exif_dict[ifd][tag]

            exif_tag_dict[ifd][piexif.TAGS[ifd][tag]["name"]] = element

    return (exif_tag_dict["GPS"]["GPSLatitude"][1][0], exif_tag_dict["GPS"]["GPSLongitude"][1][0])

def main():
    for root, dirs, files in os.walk("./pokemon"):
        for file in files:
            #filename = './pokemon/bulbasaur.jpg'  # obviously one of your own pictures
            im = Image.open("./pokemon/" + file)

            exif_dict = piexif.load(im.info.get('exif'))
            pos = exif_to_tag(exif_dict)
            plt.plot(pos[0], pos[1], "bo")
            print(pos)
    plt.show()

if __name__ == '__main__':
   main()