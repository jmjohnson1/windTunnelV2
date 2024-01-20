#!ruby
#
# This software is licensed under the Revised (3-clause) BSD license as follows:
#
# Copyright (c) 2018, Jeremy Cole <jeremy@jcole.us>
#
# All rights reserved.
#
# See the LICENSE file for more details.
#

#
# Generate the AllSensors_DLHR_subclasses.h output based on the 8*2*3=48 varieties
# of DLHR sensors.
#

RANGES = {
  "F05" => "0.5",
  "L01" => "1.0",
  "L02" => "2.0",
  "L05" => "5.0",
  "L10" => "10.0",
  "L20" => "20.0",
  "L30" => "30.0",
  "L60" => "60.0",
}

TYPES = {
  "D" => "AllSensors_DLHR::SensorType::DIFFERENTIAL",
  "G" => "AllSensors_DLHR::SensorType::GAGE",
}

RESOLUTIONS = {
  "6" => "AllSensors_DLHR::SensorResolution::RESOLUTION_16_BITS",
  "7" => "AllSensors_DLHR::SensorResolution::RESOLUTION_17_BITS",
  "8" => "AllSensors_DLHR::SensorResolution::RESOLUTION_18_BITS",
}

puts "// This file is auto-generated by generate_AllSensors_DLHR_subclasses.h. Do not edit!"
puts
puts "#ifndef ALLSENSORS_DLHR_SUBCLASSES_H"
puts "#define ALLSENSORS_DLHR_SUBCLASSES_H"
puts

RANGES.sort.each do |range_name, range_value|
  TYPES.sort.each do |type_name, type_value|
    RESOLUTIONS.sort.each do |resolution_name, resolution_value|
      class_name = "AllSensors_DLHR_#{range_name}#{type_name}_#{resolution_name}"

      puts "class #{class_name} : public AllSensors_DLHR {"
      puts "public:"
      puts "  #{class_name}(TwoWire *bus) : AllSensors_DLHR(bus, #{type_value}, #{resolution_value}, #{range_value}) {}"
      puts "  #{class_name}(uint8_t cs_pin) : AllSensors_DLHR(cs_pin, #{type_value}, #{resolution_value}, #{range_value}) {}"
      puts "  #{class_name}(uint8_t cs_pin, uint8_t mosi_pin, uint8_t miso_pin,uint8_t clk_pin) : AllSensors_DLHR(cs_pin, mosi_pin, miso_pin, clk_pin, #{type_value}, #{resolution_value}, #{range_value}) {}"
      puts "};"
      puts
    end
  end
end

puts "#endif // ALLSENSORS_DLHR_SUBCLASSES_H"
