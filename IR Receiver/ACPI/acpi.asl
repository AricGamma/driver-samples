DefinitionBlock ("ACPITABL.dat", "SSDT", 1, "MSFT", "ECHO", 1)
{
    Scope (\_SB)
    {
        //
        // Define a device node that represents IR Receiver module in A64 SoC
        //
        Device(CIRR)
        {
            Name(_HID, "AWTH0213")
            Name(_UID, 0x0)
			Method (_STA, 0, NotSerialized)
			{
				Return (0x0F)
			}
			
			Name (_CRS, ResourceTemplate (){
				
				MEMORY32FIXED(ReadWrite, 0x01F02000, 0x54,)								//CIR module register address in A64 SoC
				Interrupt(ResourceConsumer, Level, ActiveHigh, Exclusive, , ,) {69}		//Interrupt for CIR
				
			})
			
			Method (_RMV, 0, NotSerialized)
			{
				Return (Zero)
			}
        }
    }
}
