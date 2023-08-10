# capstone
Capstone project correlating the output of two blood pressure and pulse reading machines.

I believe the ouput is as follows:
Voltage = (libct_vitals_t.systolic - libct_vitals_t.diastolic) * conversionFactor
Where conversionFactor will need to be determined (ideally 100mmHg:1V)
I suspect we only need work with the libct_vitals_t package/struct.

## libct_vitals_t Struct Reference
### ◆ valid
bool libct_vitals_t::valid
The other fields are valid when this field is non-zero (true) and invalid otherwise.

### ◆ bp_status
bool libct_vitals_t::bp_status
An indicator if a valid blood pressure was found or if the algorithm failed.

True indicates pulse information is valid.

### ◆ systolic
short libct_vitals_t::systolic
Systolic measurement.

### ◆ diastolic
short libct_vitals_t::diastolic
Diastolic measurement.

## Plan
connect caretaker via blutooth to ardunio/raspberry pi
find above values
if(valid && bp_status):
	voltage = (systolic - diastolic) * conversionFactor
	output voltage to BnC cable.
else:
	handle/send error

