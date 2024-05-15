#ifndef EDFLAGHELPERS_INCLUDED
#define EDFLAGHELPERS_INCLUDED
namespace edflags {
    const unsigned long Docked = 1<<0;             // on a landing pad
    const unsigned long Landed = 1<<1;             // on planet surface
    const unsigned long LandingGearDown = 1<<2;
    const unsigned long ShieldsUp = 1<<3;
    const unsigned long Supercruise = 1<<4;
    const unsigned long FlightAssistOff = 1<<5;
    const unsigned long HardpointsDeployed = 1<<6;
    const unsigned long InWing = 1<<7;
    const unsigned long LightsOn = 1<<8;
    const unsigned long CargoScoopDeployed = 1<<9;
    const unsigned long SilentRunning = 1<<10;
    const unsigned long ScoopingFuel = 1<<11;
    const unsigned long SrvHandbrake = 1<<12;
    const unsigned long SrvTurret = 1<<13;         // using turret view
    const unsigned long SrvUnderShip = 1<<14;      //turret retracted
    const unsigned long SrvDriveAssist = 1<<15;
    const unsigned long FsdMassLocked = 1<<16;
    const unsigned long FsdCharging = 1<<17;
    const unsigned long FsdCooldown = 1<<18;
    const unsigned long LowFuel = 1<<19;           // < 25%
    const unsigned long OverHeating = 1<<20;       // > 100%, or is this 80% now ?
    const unsigned long HasLatLong = 1<<21;
    const unsigned long IsInDanger = 1<<22;
    const unsigned long BeingInterdicted = 1<<23;
    const unsigned long InMainShip = 1<<24;
    const unsigned long InFighter = 1<<25;
    const unsigned long InSRV = 1<<26;
    const unsigned long AnalysisMode = 1<<27;      // Hud in Analysis mode
    const unsigned long NightVision = 1<<28;
    const unsigned long AverageAltitude = 1<<29;   // Altitude from Average radius
    const unsigned long FsdJump = 1<<30;
    const unsigned long SrvHighBeam = 1<<31;
}
namespace edflags2 {
    const unsigned long OnFoot = 1<<0;
    const unsigned long InTaxi = 1<<1;  // (or dropship/shuttle)
    const unsigned long InMulticrew = 1<<2;  // (ie in someone else’s ship)
    const unsigned long OnFootInStation = 1<<3;
    const unsigned long OnFootOnPlanet = 1<<4;
    const unsigned long AimDownSight = 1<<5;
    const unsigned long LowOxygen = 1<<6;
    const unsigned long LowHealth = 1<<7;
    const unsigned long Cold = 1<<8;
    const unsigned long Hot = 1<<9;
    const unsigned long VeryCold = 1<<10;
    const unsigned long VeryHot = 1<<11;
    const unsigned long GlideMode = 1<<12;
    const unsigned long OnFootInHangar = 1<<13;
    const unsigned long OnFootSocialSpace = 1<<14;
    const unsigned long OnFootExterior = 1<<15;
    const unsigned long BreathableAtmosphere = 1<<16;
    const unsigned long TelepresenceMulticrew = 1<<17;
    const unsigned long PhysicalMulticrew = 1<<18;
    const unsigned long HyperdriveCharging = 1<<19;
}

#endif