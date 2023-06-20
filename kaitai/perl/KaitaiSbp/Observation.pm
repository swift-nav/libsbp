# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
use KaitaiSbp::Gnss;

use strict;
use warnings;
use IO::KaitaiStruct 0.009_000;

########################################################################
package Observation;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

}

########################################################################
package Observation::MsgSvAzEl;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{azel} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{azel}}, Observation::SvAzEl->new($self->{_io}, $self, $self->{_root});
    }
}

sub azel {
    my ($self) = @_;
    return $self->{azel};
}

########################################################################
package Observation::GnssCapb;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{gps_active} = $self->{_io}->read_u8le();
    $self->{gps_l2c} = $self->{_io}->read_u8le();
    $self->{gps_l5} = $self->{_io}->read_u8le();
    $self->{glo_active} = $self->{_io}->read_u4le();
    $self->{glo_l2of} = $self->{_io}->read_u4le();
    $self->{glo_l3} = $self->{_io}->read_u4le();
    $self->{sbas_active} = $self->{_io}->read_u8le();
    $self->{sbas_l5} = $self->{_io}->read_u8le();
    $self->{bds_active} = $self->{_io}->read_u8le();
    $self->{bds_d2nav} = $self->{_io}->read_u8le();
    $self->{bds_b2} = $self->{_io}->read_u8le();
    $self->{bds_b2a} = $self->{_io}->read_u8le();
    $self->{qzss_active} = $self->{_io}->read_u4le();
    $self->{gal_active} = $self->{_io}->read_u8le();
    $self->{gal_e5} = $self->{_io}->read_u8le();
}

sub gps_active {
    my ($self) = @_;
    return $self->{gps_active};
}

sub gps_l2c {
    my ($self) = @_;
    return $self->{gps_l2c};
}

sub gps_l5 {
    my ($self) = @_;
    return $self->{gps_l5};
}

sub glo_active {
    my ($self) = @_;
    return $self->{glo_active};
}

sub glo_l2of {
    my ($self) = @_;
    return $self->{glo_l2of};
}

sub glo_l3 {
    my ($self) = @_;
    return $self->{glo_l3};
}

sub sbas_active {
    my ($self) = @_;
    return $self->{sbas_active};
}

sub sbas_l5 {
    my ($self) = @_;
    return $self->{sbas_l5};
}

sub bds_active {
    my ($self) = @_;
    return $self->{bds_active};
}

sub bds_d2nav {
    my ($self) = @_;
    return $self->{bds_d2nav};
}

sub bds_b2 {
    my ($self) = @_;
    return $self->{bds_b2};
}

sub bds_b2a {
    my ($self) = @_;
    return $self->{bds_b2a};
}

sub qzss_active {
    my ($self) = @_;
    return $self->{qzss_active};
}

sub gal_active {
    my ($self) = @_;
    return $self->{gal_active};
}

sub gal_e5 {
    my ($self) = @_;
    return $self->{gal_e5};
}

########################################################################
package Observation::MsgGroupDelayDepB;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{t_op} = Gnss::GpsTimeSec->new($self->{_io}, $self, $self->{_root});
    $self->{sid} = Gnss::GnssSignalDep->new($self->{_io}, $self, $self->{_root});
    $self->{valid} = $self->{_io}->read_u1();
    $self->{tgd} = $self->{_io}->read_s2le();
    $self->{isc_l1ca} = $self->{_io}->read_s2le();
    $self->{isc_l2c} = $self->{_io}->read_s2le();
}

sub t_op {
    my ($self) = @_;
    return $self->{t_op};
}

sub sid {
    my ($self) = @_;
    return $self->{sid};
}

sub valid {
    my ($self) = @_;
    return $self->{valid};
}

sub tgd {
    my ($self) = @_;
    return $self->{tgd};
}

sub isc_l1ca {
    my ($self) = @_;
    return $self->{isc_l1ca};
}

sub isc_l2c {
    my ($self) = @_;
    return $self->{isc_l2c};
}

########################################################################
package Observation::ObservationHeaderDep;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{t} = Gnss::GpsTimeDep->new($self->{_io}, $self, $self->{_root});
    $self->{n_obs} = $self->{_io}->read_u1();
}

sub t {
    my ($self) = @_;
    return $self->{t};
}

sub n_obs {
    my ($self) = @_;
    return $self->{n_obs};
}

########################################################################
package Observation::AlmanacCommonContentDep;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{sid} = Gnss::GnssSignalDep->new($self->{_io}, $self, $self->{_root});
    $self->{toa} = Gnss::GpsTimeSec->new($self->{_io}, $self, $self->{_root});
    $self->{ura} = $self->{_io}->read_f8le();
    $self->{fit_interval} = $self->{_io}->read_u4le();
    $self->{valid} = $self->{_io}->read_u1();
    $self->{health_bits} = $self->{_io}->read_u1();
}

sub sid {
    my ($self) = @_;
    return $self->{sid};
}

sub toa {
    my ($self) = @_;
    return $self->{toa};
}

sub ura {
    my ($self) = @_;
    return $self->{ura};
}

sub fit_interval {
    my ($self) = @_;
    return $self->{fit_interval};
}

sub valid {
    my ($self) = @_;
    return $self->{valid};
}

sub health_bits {
    my ($self) = @_;
    return $self->{health_bits};
}

########################################################################
package Observation::EphemerisCommonContentDepA;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{sid} = Gnss::GnssSignalDep->new($self->{_io}, $self, $self->{_root});
    $self->{toe} = Gnss::GpsTimeDep->new($self->{_io}, $self, $self->{_root});
    $self->{ura} = $self->{_io}->read_f8le();
    $self->{fit_interval} = $self->{_io}->read_u4le();
    $self->{valid} = $self->{_io}->read_u1();
    $self->{health_bits} = $self->{_io}->read_u1();
}

sub sid {
    my ($self) = @_;
    return $self->{sid};
}

sub toe {
    my ($self) = @_;
    return $self->{toe};
}

sub ura {
    my ($self) = @_;
    return $self->{ura};
}

sub fit_interval {
    my ($self) = @_;
    return $self->{fit_interval};
}

sub valid {
    my ($self) = @_;
    return $self->{valid};
}

sub health_bits {
    my ($self) = @_;
    return $self->{health_bits};
}

########################################################################
package Observation::EphemerisCommonContent;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{sid} = Gnss::GnssSignal->new($self->{_io}, $self, $self->{_root});
    $self->{toe} = Gnss::GpsTimeSec->new($self->{_io}, $self, $self->{_root});
    $self->{ura} = $self->{_io}->read_f4le();
    $self->{fit_interval} = $self->{_io}->read_u4le();
    $self->{valid} = $self->{_io}->read_u1();
    $self->{health_bits} = $self->{_io}->read_u1();
}

sub sid {
    my ($self) = @_;
    return $self->{sid};
}

sub toe {
    my ($self) = @_;
    return $self->{toe};
}

sub ura {
    my ($self) = @_;
    return $self->{ura};
}

sub fit_interval {
    my ($self) = @_;
    return $self->{fit_interval};
}

sub valid {
    my ($self) = @_;
    return $self->{valid};
}

sub health_bits {
    my ($self) = @_;
    return $self->{health_bits};
}

########################################################################
package Observation::PackedObsContentDepC;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{p} = $self->{_io}->read_u4le();
    $self->{l} = Gnss::CarrierPhase->new($self->{_io}, $self, $self->{_root});
    $self->{cn0} = $self->{_io}->read_u1();
    $self->{lock} = $self->{_io}->read_u2le();
    $self->{sid} = Gnss::GnssSignalDep->new($self->{_io}, $self, $self->{_root});
}

sub p {
    my ($self) = @_;
    return $self->{p};
}

sub l {
    my ($self) = @_;
    return $self->{l};
}

sub cn0 {
    my ($self) = @_;
    return $self->{cn0};
}

sub lock {
    my ($self) = @_;
    return $self->{lock};
}

sub sid {
    my ($self) = @_;
    return $self->{sid};
}

########################################################################
package Observation::MsgEphemerisGloDepD;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{common} = Observation::EphemerisCommonContentDepB->new($self->{_io}, $self, $self->{_root});
    $self->{gamma} = $self->{_io}->read_f8le();
    $self->{tau} = $self->{_io}->read_f8le();
    $self->{d_tau} = $self->{_io}->read_f8le();
    $self->{pos} = [];
    my $n_pos = 3;
    for (my $i = 0; $i < $n_pos; $i++) {
        push @{$self->{pos}}, $self->{_io}->read_f8le();
    }
    $self->{vel} = [];
    my $n_vel = 3;
    for (my $i = 0; $i < $n_vel; $i++) {
        push @{$self->{vel}}, $self->{_io}->read_f8le();
    }
    $self->{acc} = [];
    my $n_acc = 3;
    for (my $i = 0; $i < $n_acc; $i++) {
        push @{$self->{acc}}, $self->{_io}->read_f8le();
    }
    $self->{fcn} = $self->{_io}->read_u1();
    $self->{iod} = $self->{_io}->read_u1();
}

sub common {
    my ($self) = @_;
    return $self->{common};
}

sub gamma {
    my ($self) = @_;
    return $self->{gamma};
}

sub tau {
    my ($self) = @_;
    return $self->{tau};
}

sub d_tau {
    my ($self) = @_;
    return $self->{d_tau};
}

sub pos {
    my ($self) = @_;
    return $self->{pos};
}

sub vel {
    my ($self) = @_;
    return $self->{vel};
}

sub acc {
    my ($self) = @_;
    return $self->{acc};
}

sub fcn {
    my ($self) = @_;
    return $self->{fcn};
}

sub iod {
    my ($self) = @_;
    return $self->{iod};
}

########################################################################
package Observation::MsgObsDepA;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{header} = Observation::ObservationHeaderDep->new($self->{_io}, $self, $self->{_root});
    $self->{obs} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{obs}}, Observation::PackedObsContentDepA->new($self->{_io}, $self, $self->{_root});
    }
}

sub header {
    my ($self) = @_;
    return $self->{header};
}

sub obs {
    my ($self) = @_;
    return $self->{obs};
}

########################################################################
package Observation::MsgEphemerisDepB;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{tgd} = $self->{_io}->read_f8le();
    $self->{c_rs} = $self->{_io}->read_f8le();
    $self->{c_rc} = $self->{_io}->read_f8le();
    $self->{c_uc} = $self->{_io}->read_f8le();
    $self->{c_us} = $self->{_io}->read_f8le();
    $self->{c_ic} = $self->{_io}->read_f8le();
    $self->{c_is} = $self->{_io}->read_f8le();
    $self->{dn} = $self->{_io}->read_f8le();
    $self->{m0} = $self->{_io}->read_f8le();
    $self->{ecc} = $self->{_io}->read_f8le();
    $self->{sqrta} = $self->{_io}->read_f8le();
    $self->{omega0} = $self->{_io}->read_f8le();
    $self->{omegadot} = $self->{_io}->read_f8le();
    $self->{w} = $self->{_io}->read_f8le();
    $self->{inc} = $self->{_io}->read_f8le();
    $self->{inc_dot} = $self->{_io}->read_f8le();
    $self->{af0} = $self->{_io}->read_f8le();
    $self->{af1} = $self->{_io}->read_f8le();
    $self->{af2} = $self->{_io}->read_f8le();
    $self->{toe_tow} = $self->{_io}->read_f8le();
    $self->{toe_wn} = $self->{_io}->read_u2le();
    $self->{toc_tow} = $self->{_io}->read_f8le();
    $self->{toc_wn} = $self->{_io}->read_u2le();
    $self->{valid} = $self->{_io}->read_u1();
    $self->{healthy} = $self->{_io}->read_u1();
    $self->{prn} = $self->{_io}->read_u1();
    $self->{iode} = $self->{_io}->read_u1();
}

sub tgd {
    my ($self) = @_;
    return $self->{tgd};
}

sub c_rs {
    my ($self) = @_;
    return $self->{c_rs};
}

sub c_rc {
    my ($self) = @_;
    return $self->{c_rc};
}

sub c_uc {
    my ($self) = @_;
    return $self->{c_uc};
}

sub c_us {
    my ($self) = @_;
    return $self->{c_us};
}

sub c_ic {
    my ($self) = @_;
    return $self->{c_ic};
}

sub c_is {
    my ($self) = @_;
    return $self->{c_is};
}

sub dn {
    my ($self) = @_;
    return $self->{dn};
}

sub m0 {
    my ($self) = @_;
    return $self->{m0};
}

sub ecc {
    my ($self) = @_;
    return $self->{ecc};
}

sub sqrta {
    my ($self) = @_;
    return $self->{sqrta};
}

sub omega0 {
    my ($self) = @_;
    return $self->{omega0};
}

sub omegadot {
    my ($self) = @_;
    return $self->{omegadot};
}

sub w {
    my ($self) = @_;
    return $self->{w};
}

sub inc {
    my ($self) = @_;
    return $self->{inc};
}

sub inc_dot {
    my ($self) = @_;
    return $self->{inc_dot};
}

sub af0 {
    my ($self) = @_;
    return $self->{af0};
}

sub af1 {
    my ($self) = @_;
    return $self->{af1};
}

sub af2 {
    my ($self) = @_;
    return $self->{af2};
}

sub toe_tow {
    my ($self) = @_;
    return $self->{toe_tow};
}

sub toe_wn {
    my ($self) = @_;
    return $self->{toe_wn};
}

sub toc_tow {
    my ($self) = @_;
    return $self->{toc_tow};
}

sub toc_wn {
    my ($self) = @_;
    return $self->{toc_wn};
}

sub valid {
    my ($self) = @_;
    return $self->{valid};
}

sub healthy {
    my ($self) = @_;
    return $self->{healthy};
}

sub prn {
    my ($self) = @_;
    return $self->{prn};
}

sub iode {
    my ($self) = @_;
    return $self->{iode};
}

########################################################################
package Observation::MsgObs;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{header} = Observation::ObservationHeader->new($self->{_io}, $self, $self->{_root});
    $self->{obs} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{obs}}, Observation::PackedObsContent->new($self->{_io}, $self, $self->{_root});
    }
}

sub header {
    my ($self) = @_;
    return $self->{header};
}

sub obs {
    my ($self) = @_;
    return $self->{obs};
}

########################################################################
package Observation::Doppler;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{i} = $self->{_io}->read_s2le();
    $self->{f} = $self->{_io}->read_u1();
}

sub i {
    my ($self) = @_;
    return $self->{i};
}

sub f {
    my ($self) = @_;
    return $self->{f};
}

########################################################################
package Observation::MsgAlmanacGloDep;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{common} = Observation::AlmanacCommonContentDep->new($self->{_io}, $self, $self->{_root});
    $self->{lambda_na} = $self->{_io}->read_f8le();
    $self->{t_lambda_na} = $self->{_io}->read_f8le();
    $self->{i} = $self->{_io}->read_f8le();
    $self->{t} = $self->{_io}->read_f8le();
    $self->{t_dot} = $self->{_io}->read_f8le();
    $self->{epsilon} = $self->{_io}->read_f8le();
    $self->{omega} = $self->{_io}->read_f8le();
}

sub common {
    my ($self) = @_;
    return $self->{common};
}

sub lambda_na {
    my ($self) = @_;
    return $self->{lambda_na};
}

sub t_lambda_na {
    my ($self) = @_;
    return $self->{t_lambda_na};
}

sub i {
    my ($self) = @_;
    return $self->{i};
}

sub t {
    my ($self) = @_;
    return $self->{t};
}

sub t_dot {
    my ($self) = @_;
    return $self->{t_dot};
}

sub epsilon {
    my ($self) = @_;
    return $self->{epsilon};
}

sub omega {
    my ($self) = @_;
    return $self->{omega};
}

########################################################################
package Observation::MsgAlmanacGpsDep;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{common} = Observation::AlmanacCommonContentDep->new($self->{_io}, $self, $self->{_root});
    $self->{m0} = $self->{_io}->read_f8le();
    $self->{ecc} = $self->{_io}->read_f8le();
    $self->{sqrta} = $self->{_io}->read_f8le();
    $self->{omega0} = $self->{_io}->read_f8le();
    $self->{omegadot} = $self->{_io}->read_f8le();
    $self->{w} = $self->{_io}->read_f8le();
    $self->{inc} = $self->{_io}->read_f8le();
    $self->{af0} = $self->{_io}->read_f8le();
    $self->{af1} = $self->{_io}->read_f8le();
}

sub common {
    my ($self) = @_;
    return $self->{common};
}

sub m0 {
    my ($self) = @_;
    return $self->{m0};
}

sub ecc {
    my ($self) = @_;
    return $self->{ecc};
}

sub sqrta {
    my ($self) = @_;
    return $self->{sqrta};
}

sub omega0 {
    my ($self) = @_;
    return $self->{omega0};
}

sub omegadot {
    my ($self) = @_;
    return $self->{omegadot};
}

sub w {
    my ($self) = @_;
    return $self->{w};
}

sub inc {
    my ($self) = @_;
    return $self->{inc};
}

sub af0 {
    my ($self) = @_;
    return $self->{af0};
}

sub af1 {
    my ($self) = @_;
    return $self->{af1};
}

########################################################################
package Observation::SvAzEl;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{sid} = Gnss::GnssSignal->new($self->{_io}, $self, $self->{_root});
    $self->{az} = $self->{_io}->read_u1();
    $self->{el} = $self->{_io}->read_s1();
}

sub sid {
    my ($self) = @_;
    return $self->{sid};
}

sub az {
    my ($self) = @_;
    return $self->{az};
}

sub el {
    my ($self) = @_;
    return $self->{el};
}

########################################################################
package Observation::MsgGloBiases;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{mask} = $self->{_io}->read_u1();
    $self->{l1ca_bias} = $self->{_io}->read_s2le();
    $self->{l1p_bias} = $self->{_io}->read_s2le();
    $self->{l2ca_bias} = $self->{_io}->read_s2le();
    $self->{l2p_bias} = $self->{_io}->read_s2le();
}

sub mask {
    my ($self) = @_;
    return $self->{mask};
}

sub l1ca_bias {
    my ($self) = @_;
    return $self->{l1ca_bias};
}

sub l1p_bias {
    my ($self) = @_;
    return $self->{l1p_bias};
}

sub l2ca_bias {
    my ($self) = @_;
    return $self->{l2ca_bias};
}

sub l2p_bias {
    my ($self) = @_;
    return $self->{l2p_bias};
}

########################################################################
package Observation::MsgEphemerisSbasDepB;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{common} = Observation::EphemerisCommonContentDepB->new($self->{_io}, $self, $self->{_root});
    $self->{pos} = [];
    my $n_pos = 3;
    for (my $i = 0; $i < $n_pos; $i++) {
        push @{$self->{pos}}, $self->{_io}->read_f8le();
    }
    $self->{vel} = [];
    my $n_vel = 3;
    for (my $i = 0; $i < $n_vel; $i++) {
        push @{$self->{vel}}, $self->{_io}->read_f8le();
    }
    $self->{acc} = [];
    my $n_acc = 3;
    for (my $i = 0; $i < $n_acc; $i++) {
        push @{$self->{acc}}, $self->{_io}->read_f8le();
    }
    $self->{a_gf0} = $self->{_io}->read_f8le();
    $self->{a_gf1} = $self->{_io}->read_f8le();
}

sub common {
    my ($self) = @_;
    return $self->{common};
}

sub pos {
    my ($self) = @_;
    return $self->{pos};
}

sub vel {
    my ($self) = @_;
    return $self->{vel};
}

sub acc {
    my ($self) = @_;
    return $self->{acc};
}

sub a_gf0 {
    my ($self) = @_;
    return $self->{a_gf0};
}

sub a_gf1 {
    my ($self) = @_;
    return $self->{a_gf1};
}

########################################################################
package Observation::MsgEphemerisGpsDepE;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{common} = Observation::EphemerisCommonContentDepA->new($self->{_io}, $self, $self->{_root});
    $self->{tgd} = $self->{_io}->read_f8le();
    $self->{c_rs} = $self->{_io}->read_f8le();
    $self->{c_rc} = $self->{_io}->read_f8le();
    $self->{c_uc} = $self->{_io}->read_f8le();
    $self->{c_us} = $self->{_io}->read_f8le();
    $self->{c_ic} = $self->{_io}->read_f8le();
    $self->{c_is} = $self->{_io}->read_f8le();
    $self->{dn} = $self->{_io}->read_f8le();
    $self->{m0} = $self->{_io}->read_f8le();
    $self->{ecc} = $self->{_io}->read_f8le();
    $self->{sqrta} = $self->{_io}->read_f8le();
    $self->{omega0} = $self->{_io}->read_f8le();
    $self->{omegadot} = $self->{_io}->read_f8le();
    $self->{w} = $self->{_io}->read_f8le();
    $self->{inc} = $self->{_io}->read_f8le();
    $self->{inc_dot} = $self->{_io}->read_f8le();
    $self->{af0} = $self->{_io}->read_f8le();
    $self->{af1} = $self->{_io}->read_f8le();
    $self->{af2} = $self->{_io}->read_f8le();
    $self->{toc} = Gnss::GpsTimeDep->new($self->{_io}, $self, $self->{_root});
    $self->{iode} = $self->{_io}->read_u1();
    $self->{iodc} = $self->{_io}->read_u2le();
}

sub common {
    my ($self) = @_;
    return $self->{common};
}

sub tgd {
    my ($self) = @_;
    return $self->{tgd};
}

sub c_rs {
    my ($self) = @_;
    return $self->{c_rs};
}

sub c_rc {
    my ($self) = @_;
    return $self->{c_rc};
}

sub c_uc {
    my ($self) = @_;
    return $self->{c_uc};
}

sub c_us {
    my ($self) = @_;
    return $self->{c_us};
}

sub c_ic {
    my ($self) = @_;
    return $self->{c_ic};
}

sub c_is {
    my ($self) = @_;
    return $self->{c_is};
}

sub dn {
    my ($self) = @_;
    return $self->{dn};
}

sub m0 {
    my ($self) = @_;
    return $self->{m0};
}

sub ecc {
    my ($self) = @_;
    return $self->{ecc};
}

sub sqrta {
    my ($self) = @_;
    return $self->{sqrta};
}

sub omega0 {
    my ($self) = @_;
    return $self->{omega0};
}

sub omegadot {
    my ($self) = @_;
    return $self->{omegadot};
}

sub w {
    my ($self) = @_;
    return $self->{w};
}

sub inc {
    my ($self) = @_;
    return $self->{inc};
}

sub inc_dot {
    my ($self) = @_;
    return $self->{inc_dot};
}

sub af0 {
    my ($self) = @_;
    return $self->{af0};
}

sub af1 {
    my ($self) = @_;
    return $self->{af1};
}

sub af2 {
    my ($self) = @_;
    return $self->{af2};
}

sub toc {
    my ($self) = @_;
    return $self->{toc};
}

sub iode {
    my ($self) = @_;
    return $self->{iode};
}

sub iodc {
    my ($self) = @_;
    return $self->{iodc};
}

########################################################################
package Observation::MsgGnssCapb;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{t_nmct} = Gnss::GpsTimeSec->new($self->{_io}, $self, $self->{_root});
    $self->{gc} = Observation::GnssCapb->new($self->{_io}, $self, $self->{_root});
}

sub t_nmct {
    my ($self) = @_;
    return $self->{t_nmct};
}

sub gc {
    my ($self) = @_;
    return $self->{gc};
}

########################################################################
package Observation::MsgAlmanacGps;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{common} = Observation::AlmanacCommonContent->new($self->{_io}, $self, $self->{_root});
    $self->{m0} = $self->{_io}->read_f8le();
    $self->{ecc} = $self->{_io}->read_f8le();
    $self->{sqrta} = $self->{_io}->read_f8le();
    $self->{omega0} = $self->{_io}->read_f8le();
    $self->{omegadot} = $self->{_io}->read_f8le();
    $self->{w} = $self->{_io}->read_f8le();
    $self->{inc} = $self->{_io}->read_f8le();
    $self->{af0} = $self->{_io}->read_f8le();
    $self->{af1} = $self->{_io}->read_f8le();
}

sub common {
    my ($self) = @_;
    return $self->{common};
}

sub m0 {
    my ($self) = @_;
    return $self->{m0};
}

sub ecc {
    my ($self) = @_;
    return $self->{ecc};
}

sub sqrta {
    my ($self) = @_;
    return $self->{sqrta};
}

sub omega0 {
    my ($self) = @_;
    return $self->{omega0};
}

sub omegadot {
    my ($self) = @_;
    return $self->{omegadot};
}

sub w {
    my ($self) = @_;
    return $self->{w};
}

sub inc {
    my ($self) = @_;
    return $self->{inc};
}

sub af0 {
    my ($self) = @_;
    return $self->{af0};
}

sub af1 {
    my ($self) = @_;
    return $self->{af1};
}

########################################################################
package Observation::MsgEphemerisQzss;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{common} = Observation::EphemerisCommonContent->new($self->{_io}, $self, $self->{_root});
    $self->{tgd} = $self->{_io}->read_f4le();
    $self->{c_rs} = $self->{_io}->read_f4le();
    $self->{c_rc} = $self->{_io}->read_f4le();
    $self->{c_uc} = $self->{_io}->read_f4le();
    $self->{c_us} = $self->{_io}->read_f4le();
    $self->{c_ic} = $self->{_io}->read_f4le();
    $self->{c_is} = $self->{_io}->read_f4le();
    $self->{dn} = $self->{_io}->read_f8le();
    $self->{m0} = $self->{_io}->read_f8le();
    $self->{ecc} = $self->{_io}->read_f8le();
    $self->{sqrta} = $self->{_io}->read_f8le();
    $self->{omega0} = $self->{_io}->read_f8le();
    $self->{omegadot} = $self->{_io}->read_f8le();
    $self->{w} = $self->{_io}->read_f8le();
    $self->{inc} = $self->{_io}->read_f8le();
    $self->{inc_dot} = $self->{_io}->read_f8le();
    $self->{af0} = $self->{_io}->read_f4le();
    $self->{af1} = $self->{_io}->read_f4le();
    $self->{af2} = $self->{_io}->read_f4le();
    $self->{toc} = Gnss::GpsTimeSec->new($self->{_io}, $self, $self->{_root});
    $self->{iode} = $self->{_io}->read_u1();
    $self->{iodc} = $self->{_io}->read_u2le();
}

sub common {
    my ($self) = @_;
    return $self->{common};
}

sub tgd {
    my ($self) = @_;
    return $self->{tgd};
}

sub c_rs {
    my ($self) = @_;
    return $self->{c_rs};
}

sub c_rc {
    my ($self) = @_;
    return $self->{c_rc};
}

sub c_uc {
    my ($self) = @_;
    return $self->{c_uc};
}

sub c_us {
    my ($self) = @_;
    return $self->{c_us};
}

sub c_ic {
    my ($self) = @_;
    return $self->{c_ic};
}

sub c_is {
    my ($self) = @_;
    return $self->{c_is};
}

sub dn {
    my ($self) = @_;
    return $self->{dn};
}

sub m0 {
    my ($self) = @_;
    return $self->{m0};
}

sub ecc {
    my ($self) = @_;
    return $self->{ecc};
}

sub sqrta {
    my ($self) = @_;
    return $self->{sqrta};
}

sub omega0 {
    my ($self) = @_;
    return $self->{omega0};
}

sub omegadot {
    my ($self) = @_;
    return $self->{omegadot};
}

sub w {
    my ($self) = @_;
    return $self->{w};
}

sub inc {
    my ($self) = @_;
    return $self->{inc};
}

sub inc_dot {
    my ($self) = @_;
    return $self->{inc_dot};
}

sub af0 {
    my ($self) = @_;
    return $self->{af0};
}

sub af1 {
    my ($self) = @_;
    return $self->{af1};
}

sub af2 {
    my ($self) = @_;
    return $self->{af2};
}

sub toc {
    my ($self) = @_;
    return $self->{toc};
}

sub iode {
    my ($self) = @_;
    return $self->{iode};
}

sub iodc {
    my ($self) = @_;
    return $self->{iodc};
}

########################################################################
package Observation::MsgGroupDelayDepA;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{t_op} = Gnss::GpsTimeDep->new($self->{_io}, $self, $self->{_root});
    $self->{prn} = $self->{_io}->read_u1();
    $self->{valid} = $self->{_io}->read_u1();
    $self->{tgd} = $self->{_io}->read_s2le();
    $self->{isc_l1ca} = $self->{_io}->read_s2le();
    $self->{isc_l2c} = $self->{_io}->read_s2le();
}

sub t_op {
    my ($self) = @_;
    return $self->{t_op};
}

sub prn {
    my ($self) = @_;
    return $self->{prn};
}

sub valid {
    my ($self) = @_;
    return $self->{valid};
}

sub tgd {
    my ($self) = @_;
    return $self->{tgd};
}

sub isc_l1ca {
    my ($self) = @_;
    return $self->{isc_l1ca};
}

sub isc_l2c {
    my ($self) = @_;
    return $self->{isc_l2c};
}

########################################################################
package Observation::MsgEphemerisDepC;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{tgd} = $self->{_io}->read_f8le();
    $self->{c_rs} = $self->{_io}->read_f8le();
    $self->{c_rc} = $self->{_io}->read_f8le();
    $self->{c_uc} = $self->{_io}->read_f8le();
    $self->{c_us} = $self->{_io}->read_f8le();
    $self->{c_ic} = $self->{_io}->read_f8le();
    $self->{c_is} = $self->{_io}->read_f8le();
    $self->{dn} = $self->{_io}->read_f8le();
    $self->{m0} = $self->{_io}->read_f8le();
    $self->{ecc} = $self->{_io}->read_f8le();
    $self->{sqrta} = $self->{_io}->read_f8le();
    $self->{omega0} = $self->{_io}->read_f8le();
    $self->{omegadot} = $self->{_io}->read_f8le();
    $self->{w} = $self->{_io}->read_f8le();
    $self->{inc} = $self->{_io}->read_f8le();
    $self->{inc_dot} = $self->{_io}->read_f8le();
    $self->{af0} = $self->{_io}->read_f8le();
    $self->{af1} = $self->{_io}->read_f8le();
    $self->{af2} = $self->{_io}->read_f8le();
    $self->{toe_tow} = $self->{_io}->read_f8le();
    $self->{toe_wn} = $self->{_io}->read_u2le();
    $self->{toc_tow} = $self->{_io}->read_f8le();
    $self->{toc_wn} = $self->{_io}->read_u2le();
    $self->{valid} = $self->{_io}->read_u1();
    $self->{healthy} = $self->{_io}->read_u1();
    $self->{sid} = Gnss::GnssSignalDep->new($self->{_io}, $self, $self->{_root});
    $self->{iode} = $self->{_io}->read_u1();
    $self->{iodc} = $self->{_io}->read_u2le();
    $self->{reserved} = $self->{_io}->read_u4le();
}

sub tgd {
    my ($self) = @_;
    return $self->{tgd};
}

sub c_rs {
    my ($self) = @_;
    return $self->{c_rs};
}

sub c_rc {
    my ($self) = @_;
    return $self->{c_rc};
}

sub c_uc {
    my ($self) = @_;
    return $self->{c_uc};
}

sub c_us {
    my ($self) = @_;
    return $self->{c_us};
}

sub c_ic {
    my ($self) = @_;
    return $self->{c_ic};
}

sub c_is {
    my ($self) = @_;
    return $self->{c_is};
}

sub dn {
    my ($self) = @_;
    return $self->{dn};
}

sub m0 {
    my ($self) = @_;
    return $self->{m0};
}

sub ecc {
    my ($self) = @_;
    return $self->{ecc};
}

sub sqrta {
    my ($self) = @_;
    return $self->{sqrta};
}

sub omega0 {
    my ($self) = @_;
    return $self->{omega0};
}

sub omegadot {
    my ($self) = @_;
    return $self->{omegadot};
}

sub w {
    my ($self) = @_;
    return $self->{w};
}

sub inc {
    my ($self) = @_;
    return $self->{inc};
}

sub inc_dot {
    my ($self) = @_;
    return $self->{inc_dot};
}

sub af0 {
    my ($self) = @_;
    return $self->{af0};
}

sub af1 {
    my ($self) = @_;
    return $self->{af1};
}

sub af2 {
    my ($self) = @_;
    return $self->{af2};
}

sub toe_tow {
    my ($self) = @_;
    return $self->{toe_tow};
}

sub toe_wn {
    my ($self) = @_;
    return $self->{toe_wn};
}

sub toc_tow {
    my ($self) = @_;
    return $self->{toc_tow};
}

sub toc_wn {
    my ($self) = @_;
    return $self->{toc_wn};
}

sub valid {
    my ($self) = @_;
    return $self->{valid};
}

sub healthy {
    my ($self) = @_;
    return $self->{healthy};
}

sub sid {
    my ($self) = @_;
    return $self->{sid};
}

sub iode {
    my ($self) = @_;
    return $self->{iode};
}

sub iodc {
    my ($self) = @_;
    return $self->{iodc};
}

sub reserved {
    my ($self) = @_;
    return $self->{reserved};
}

########################################################################
package Observation::CarrierPhaseDepA;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{i} = $self->{_io}->read_s4le();
    $self->{f} = $self->{_io}->read_u1();
}

sub i {
    my ($self) = @_;
    return $self->{i};
}

sub f {
    my ($self) = @_;
    return $self->{f};
}

########################################################################
package Observation::MsgEphemerisGal;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{common} = Observation::EphemerisCommonContent->new($self->{_io}, $self, $self->{_root});
    $self->{bgd_e1e5a} = $self->{_io}->read_f4le();
    $self->{bgd_e1e5b} = $self->{_io}->read_f4le();
    $self->{c_rs} = $self->{_io}->read_f4le();
    $self->{c_rc} = $self->{_io}->read_f4le();
    $self->{c_uc} = $self->{_io}->read_f4le();
    $self->{c_us} = $self->{_io}->read_f4le();
    $self->{c_ic} = $self->{_io}->read_f4le();
    $self->{c_is} = $self->{_io}->read_f4le();
    $self->{dn} = $self->{_io}->read_f8le();
    $self->{m0} = $self->{_io}->read_f8le();
    $self->{ecc} = $self->{_io}->read_f8le();
    $self->{sqrta} = $self->{_io}->read_f8le();
    $self->{omega0} = $self->{_io}->read_f8le();
    $self->{omegadot} = $self->{_io}->read_f8le();
    $self->{w} = $self->{_io}->read_f8le();
    $self->{inc} = $self->{_io}->read_f8le();
    $self->{inc_dot} = $self->{_io}->read_f8le();
    $self->{af0} = $self->{_io}->read_f8le();
    $self->{af1} = $self->{_io}->read_f8le();
    $self->{af2} = $self->{_io}->read_f4le();
    $self->{toc} = Gnss::GpsTimeSec->new($self->{_io}, $self, $self->{_root});
    $self->{iode} = $self->{_io}->read_u2le();
    $self->{iodc} = $self->{_io}->read_u2le();
    $self->{source} = $self->{_io}->read_u1();
}

sub common {
    my ($self) = @_;
    return $self->{common};
}

sub bgd_e1e5a {
    my ($self) = @_;
    return $self->{bgd_e1e5a};
}

sub bgd_e1e5b {
    my ($self) = @_;
    return $self->{bgd_e1e5b};
}

sub c_rs {
    my ($self) = @_;
    return $self->{c_rs};
}

sub c_rc {
    my ($self) = @_;
    return $self->{c_rc};
}

sub c_uc {
    my ($self) = @_;
    return $self->{c_uc};
}

sub c_us {
    my ($self) = @_;
    return $self->{c_us};
}

sub c_ic {
    my ($self) = @_;
    return $self->{c_ic};
}

sub c_is {
    my ($self) = @_;
    return $self->{c_is};
}

sub dn {
    my ($self) = @_;
    return $self->{dn};
}

sub m0 {
    my ($self) = @_;
    return $self->{m0};
}

sub ecc {
    my ($self) = @_;
    return $self->{ecc};
}

sub sqrta {
    my ($self) = @_;
    return $self->{sqrta};
}

sub omega0 {
    my ($self) = @_;
    return $self->{omega0};
}

sub omegadot {
    my ($self) = @_;
    return $self->{omegadot};
}

sub w {
    my ($self) = @_;
    return $self->{w};
}

sub inc {
    my ($self) = @_;
    return $self->{inc};
}

sub inc_dot {
    my ($self) = @_;
    return $self->{inc_dot};
}

sub af0 {
    my ($self) = @_;
    return $self->{af0};
}

sub af1 {
    my ($self) = @_;
    return $self->{af1};
}

sub af2 {
    my ($self) = @_;
    return $self->{af2};
}

sub toc {
    my ($self) = @_;
    return $self->{toc};
}

sub iode {
    my ($self) = @_;
    return $self->{iode};
}

sub iodc {
    my ($self) = @_;
    return $self->{iodc};
}

sub source {
    my ($self) = @_;
    return $self->{source};
}

########################################################################
package Observation::PackedOsrContent;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{p} = $self->{_io}->read_u4le();
    $self->{l} = Gnss::CarrierPhase->new($self->{_io}, $self, $self->{_root});
    $self->{lock} = $self->{_io}->read_u1();
    $self->{flags} = $self->{_io}->read_u1();
    $self->{sid} = Gnss::GnssSignal->new($self->{_io}, $self, $self->{_root});
    $self->{iono_std} = $self->{_io}->read_u2le();
    $self->{tropo_std} = $self->{_io}->read_u2le();
    $self->{range_std} = $self->{_io}->read_u2le();
}

sub p {
    my ($self) = @_;
    return $self->{p};
}

sub l {
    my ($self) = @_;
    return $self->{l};
}

sub lock {
    my ($self) = @_;
    return $self->{lock};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

sub sid {
    my ($self) = @_;
    return $self->{sid};
}

sub iono_std {
    my ($self) = @_;
    return $self->{iono_std};
}

sub tropo_std {
    my ($self) = @_;
    return $self->{tropo_std};
}

sub range_std {
    my ($self) = @_;
    return $self->{range_std};
}

########################################################################
package Observation::MsgEphemerisBds;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{common} = Observation::EphemerisCommonContent->new($self->{_io}, $self, $self->{_root});
    $self->{tgd1} = $self->{_io}->read_f4le();
    $self->{tgd2} = $self->{_io}->read_f4le();
    $self->{c_rs} = $self->{_io}->read_f4le();
    $self->{c_rc} = $self->{_io}->read_f4le();
    $self->{c_uc} = $self->{_io}->read_f4le();
    $self->{c_us} = $self->{_io}->read_f4le();
    $self->{c_ic} = $self->{_io}->read_f4le();
    $self->{c_is} = $self->{_io}->read_f4le();
    $self->{dn} = $self->{_io}->read_f8le();
    $self->{m0} = $self->{_io}->read_f8le();
    $self->{ecc} = $self->{_io}->read_f8le();
    $self->{sqrta} = $self->{_io}->read_f8le();
    $self->{omega0} = $self->{_io}->read_f8le();
    $self->{omegadot} = $self->{_io}->read_f8le();
    $self->{w} = $self->{_io}->read_f8le();
    $self->{inc} = $self->{_io}->read_f8le();
    $self->{inc_dot} = $self->{_io}->read_f8le();
    $self->{af0} = $self->{_io}->read_f8le();
    $self->{af1} = $self->{_io}->read_f4le();
    $self->{af2} = $self->{_io}->read_f4le();
    $self->{toc} = Gnss::GpsTimeSec->new($self->{_io}, $self, $self->{_root});
    $self->{iode} = $self->{_io}->read_u1();
    $self->{iodc} = $self->{_io}->read_u2le();
}

sub common {
    my ($self) = @_;
    return $self->{common};
}

sub tgd1 {
    my ($self) = @_;
    return $self->{tgd1};
}

sub tgd2 {
    my ($self) = @_;
    return $self->{tgd2};
}

sub c_rs {
    my ($self) = @_;
    return $self->{c_rs};
}

sub c_rc {
    my ($self) = @_;
    return $self->{c_rc};
}

sub c_uc {
    my ($self) = @_;
    return $self->{c_uc};
}

sub c_us {
    my ($self) = @_;
    return $self->{c_us};
}

sub c_ic {
    my ($self) = @_;
    return $self->{c_ic};
}

sub c_is {
    my ($self) = @_;
    return $self->{c_is};
}

sub dn {
    my ($self) = @_;
    return $self->{dn};
}

sub m0 {
    my ($self) = @_;
    return $self->{m0};
}

sub ecc {
    my ($self) = @_;
    return $self->{ecc};
}

sub sqrta {
    my ($self) = @_;
    return $self->{sqrta};
}

sub omega0 {
    my ($self) = @_;
    return $self->{omega0};
}

sub omegadot {
    my ($self) = @_;
    return $self->{omegadot};
}

sub w {
    my ($self) = @_;
    return $self->{w};
}

sub inc {
    my ($self) = @_;
    return $self->{inc};
}

sub inc_dot {
    my ($self) = @_;
    return $self->{inc_dot};
}

sub af0 {
    my ($self) = @_;
    return $self->{af0};
}

sub af1 {
    my ($self) = @_;
    return $self->{af1};
}

sub af2 {
    my ($self) = @_;
    return $self->{af2};
}

sub toc {
    my ($self) = @_;
    return $self->{toc};
}

sub iode {
    my ($self) = @_;
    return $self->{iode};
}

sub iodc {
    my ($self) = @_;
    return $self->{iodc};
}

########################################################################
package Observation::MsgEphemerisGpsDepF;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{common} = Observation::EphemerisCommonContentDepB->new($self->{_io}, $self, $self->{_root});
    $self->{tgd} = $self->{_io}->read_f8le();
    $self->{c_rs} = $self->{_io}->read_f8le();
    $self->{c_rc} = $self->{_io}->read_f8le();
    $self->{c_uc} = $self->{_io}->read_f8le();
    $self->{c_us} = $self->{_io}->read_f8le();
    $self->{c_ic} = $self->{_io}->read_f8le();
    $self->{c_is} = $self->{_io}->read_f8le();
    $self->{dn} = $self->{_io}->read_f8le();
    $self->{m0} = $self->{_io}->read_f8le();
    $self->{ecc} = $self->{_io}->read_f8le();
    $self->{sqrta} = $self->{_io}->read_f8le();
    $self->{omega0} = $self->{_io}->read_f8le();
    $self->{omegadot} = $self->{_io}->read_f8le();
    $self->{w} = $self->{_io}->read_f8le();
    $self->{inc} = $self->{_io}->read_f8le();
    $self->{inc_dot} = $self->{_io}->read_f8le();
    $self->{af0} = $self->{_io}->read_f8le();
    $self->{af1} = $self->{_io}->read_f8le();
    $self->{af2} = $self->{_io}->read_f8le();
    $self->{toc} = Gnss::GpsTimeSec->new($self->{_io}, $self, $self->{_root});
    $self->{iode} = $self->{_io}->read_u1();
    $self->{iodc} = $self->{_io}->read_u2le();
}

sub common {
    my ($self) = @_;
    return $self->{common};
}

sub tgd {
    my ($self) = @_;
    return $self->{tgd};
}

sub c_rs {
    my ($self) = @_;
    return $self->{c_rs};
}

sub c_rc {
    my ($self) = @_;
    return $self->{c_rc};
}

sub c_uc {
    my ($self) = @_;
    return $self->{c_uc};
}

sub c_us {
    my ($self) = @_;
    return $self->{c_us};
}

sub c_ic {
    my ($self) = @_;
    return $self->{c_ic};
}

sub c_is {
    my ($self) = @_;
    return $self->{c_is};
}

sub dn {
    my ($self) = @_;
    return $self->{dn};
}

sub m0 {
    my ($self) = @_;
    return $self->{m0};
}

sub ecc {
    my ($self) = @_;
    return $self->{ecc};
}

sub sqrta {
    my ($self) = @_;
    return $self->{sqrta};
}

sub omega0 {
    my ($self) = @_;
    return $self->{omega0};
}

sub omegadot {
    my ($self) = @_;
    return $self->{omegadot};
}

sub w {
    my ($self) = @_;
    return $self->{w};
}

sub inc {
    my ($self) = @_;
    return $self->{inc};
}

sub inc_dot {
    my ($self) = @_;
    return $self->{inc_dot};
}

sub af0 {
    my ($self) = @_;
    return $self->{af0};
}

sub af1 {
    my ($self) = @_;
    return $self->{af1};
}

sub af2 {
    my ($self) = @_;
    return $self->{af2};
}

sub toc {
    my ($self) = @_;
    return $self->{toc};
}

sub iode {
    my ($self) = @_;
    return $self->{iode};
}

sub iodc {
    my ($self) = @_;
    return $self->{iodc};
}

########################################################################
package Observation::ObservationHeader;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{t} = Gnss::GpsTime->new($self->{_io}, $self, $self->{_root});
    $self->{n_obs} = $self->{_io}->read_u1();
}

sub t {
    my ($self) = @_;
    return $self->{t};
}

sub n_obs {
    my ($self) = @_;
    return $self->{n_obs};
}

########################################################################
package Observation::MsgEphemerisSbasDepA;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{common} = Observation::EphemerisCommonContentDepA->new($self->{_io}, $self, $self->{_root});
    $self->{pos} = [];
    my $n_pos = 3;
    for (my $i = 0; $i < $n_pos; $i++) {
        push @{$self->{pos}}, $self->{_io}->read_f8le();
    }
    $self->{vel} = [];
    my $n_vel = 3;
    for (my $i = 0; $i < $n_vel; $i++) {
        push @{$self->{vel}}, $self->{_io}->read_f8le();
    }
    $self->{acc} = [];
    my $n_acc = 3;
    for (my $i = 0; $i < $n_acc; $i++) {
        push @{$self->{acc}}, $self->{_io}->read_f8le();
    }
    $self->{a_gf0} = $self->{_io}->read_f8le();
    $self->{a_gf1} = $self->{_io}->read_f8le();
}

sub common {
    my ($self) = @_;
    return $self->{common};
}

sub pos {
    my ($self) = @_;
    return $self->{pos};
}

sub vel {
    my ($self) = @_;
    return $self->{vel};
}

sub acc {
    my ($self) = @_;
    return $self->{acc};
}

sub a_gf0 {
    my ($self) = @_;
    return $self->{a_gf0};
}

sub a_gf1 {
    my ($self) = @_;
    return $self->{a_gf1};
}

########################################################################
package Observation::PackedObsContent;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{p} = $self->{_io}->read_u4le();
    $self->{l} = Gnss::CarrierPhase->new($self->{_io}, $self, $self->{_root});
    $self->{d} = Observation::Doppler->new($self->{_io}, $self, $self->{_root});
    $self->{cn0} = $self->{_io}->read_u1();
    $self->{lock} = $self->{_io}->read_u1();
    $self->{flags} = $self->{_io}->read_u1();
    $self->{sid} = Gnss::GnssSignal->new($self->{_io}, $self, $self->{_root});
}

sub p {
    my ($self) = @_;
    return $self->{p};
}

sub l {
    my ($self) = @_;
    return $self->{l};
}

sub d {
    my ($self) = @_;
    return $self->{d};
}

sub cn0 {
    my ($self) = @_;
    return $self->{cn0};
}

sub lock {
    my ($self) = @_;
    return $self->{lock};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

sub sid {
    my ($self) = @_;
    return $self->{sid};
}

########################################################################
package Observation::MsgBasePosEcef;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{x} = $self->{_io}->read_f8le();
    $self->{y} = $self->{_io}->read_f8le();
    $self->{z} = $self->{_io}->read_f8le();
}

sub x {
    my ($self) = @_;
    return $self->{x};
}

sub y {
    my ($self) = @_;
    return $self->{y};
}

sub z {
    my ($self) = @_;
    return $self->{z};
}

########################################################################
package Observation::MsgEphemerisGloDepA;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{common} = Observation::EphemerisCommonContentDepA->new($self->{_io}, $self, $self->{_root});
    $self->{gamma} = $self->{_io}->read_f8le();
    $self->{tau} = $self->{_io}->read_f8le();
    $self->{pos} = [];
    my $n_pos = 3;
    for (my $i = 0; $i < $n_pos; $i++) {
        push @{$self->{pos}}, $self->{_io}->read_f8le();
    }
    $self->{vel} = [];
    my $n_vel = 3;
    for (my $i = 0; $i < $n_vel; $i++) {
        push @{$self->{vel}}, $self->{_io}->read_f8le();
    }
    $self->{acc} = [];
    my $n_acc = 3;
    for (my $i = 0; $i < $n_acc; $i++) {
        push @{$self->{acc}}, $self->{_io}->read_f8le();
    }
}

sub common {
    my ($self) = @_;
    return $self->{common};
}

sub gamma {
    my ($self) = @_;
    return $self->{gamma};
}

sub tau {
    my ($self) = @_;
    return $self->{tau};
}

sub pos {
    my ($self) = @_;
    return $self->{pos};
}

sub vel {
    my ($self) = @_;
    return $self->{vel};
}

sub acc {
    my ($self) = @_;
    return $self->{acc};
}

########################################################################
package Observation::MsgGroupDelay;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{t_op} = Gnss::GpsTimeSec->new($self->{_io}, $self, $self->{_root});
    $self->{sid} = Gnss::GnssSignal->new($self->{_io}, $self, $self->{_root});
    $self->{valid} = $self->{_io}->read_u1();
    $self->{tgd} = $self->{_io}->read_s2le();
    $self->{isc_l1ca} = $self->{_io}->read_s2le();
    $self->{isc_l2c} = $self->{_io}->read_s2le();
}

sub t_op {
    my ($self) = @_;
    return $self->{t_op};
}

sub sid {
    my ($self) = @_;
    return $self->{sid};
}

sub valid {
    my ($self) = @_;
    return $self->{valid};
}

sub tgd {
    my ($self) = @_;
    return $self->{tgd};
}

sub isc_l1ca {
    my ($self) = @_;
    return $self->{isc_l1ca};
}

sub isc_l2c {
    my ($self) = @_;
    return $self->{isc_l2c};
}

########################################################################
package Observation::MsgAlmanacGlo;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{common} = Observation::AlmanacCommonContent->new($self->{_io}, $self, $self->{_root});
    $self->{lambda_na} = $self->{_io}->read_f8le();
    $self->{t_lambda_na} = $self->{_io}->read_f8le();
    $self->{i} = $self->{_io}->read_f8le();
    $self->{t} = $self->{_io}->read_f8le();
    $self->{t_dot} = $self->{_io}->read_f8le();
    $self->{epsilon} = $self->{_io}->read_f8le();
    $self->{omega} = $self->{_io}->read_f8le();
}

sub common {
    my ($self) = @_;
    return $self->{common};
}

sub lambda_na {
    my ($self) = @_;
    return $self->{lambda_na};
}

sub t_lambda_na {
    my ($self) = @_;
    return $self->{t_lambda_na};
}

sub i {
    my ($self) = @_;
    return $self->{i};
}

sub t {
    my ($self) = @_;
    return $self->{t};
}

sub t_dot {
    my ($self) = @_;
    return $self->{t_dot};
}

sub epsilon {
    my ($self) = @_;
    return $self->{epsilon};
}

sub omega {
    my ($self) = @_;
    return $self->{omega};
}

########################################################################
package Observation::MsgEphemerisGalDepA;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{common} = Observation::EphemerisCommonContent->new($self->{_io}, $self, $self->{_root});
    $self->{bgd_e1e5a} = $self->{_io}->read_f4le();
    $self->{bgd_e1e5b} = $self->{_io}->read_f4le();
    $self->{c_rs} = $self->{_io}->read_f4le();
    $self->{c_rc} = $self->{_io}->read_f4le();
    $self->{c_uc} = $self->{_io}->read_f4le();
    $self->{c_us} = $self->{_io}->read_f4le();
    $self->{c_ic} = $self->{_io}->read_f4le();
    $self->{c_is} = $self->{_io}->read_f4le();
    $self->{dn} = $self->{_io}->read_f8le();
    $self->{m0} = $self->{_io}->read_f8le();
    $self->{ecc} = $self->{_io}->read_f8le();
    $self->{sqrta} = $self->{_io}->read_f8le();
    $self->{omega0} = $self->{_io}->read_f8le();
    $self->{omegadot} = $self->{_io}->read_f8le();
    $self->{w} = $self->{_io}->read_f8le();
    $self->{inc} = $self->{_io}->read_f8le();
    $self->{inc_dot} = $self->{_io}->read_f8le();
    $self->{af0} = $self->{_io}->read_f8le();
    $self->{af1} = $self->{_io}->read_f8le();
    $self->{af2} = $self->{_io}->read_f4le();
    $self->{toc} = Gnss::GpsTimeSec->new($self->{_io}, $self, $self->{_root});
    $self->{iode} = $self->{_io}->read_u2le();
    $self->{iodc} = $self->{_io}->read_u2le();
}

sub common {
    my ($self) = @_;
    return $self->{common};
}

sub bgd_e1e5a {
    my ($self) = @_;
    return $self->{bgd_e1e5a};
}

sub bgd_e1e5b {
    my ($self) = @_;
    return $self->{bgd_e1e5b};
}

sub c_rs {
    my ($self) = @_;
    return $self->{c_rs};
}

sub c_rc {
    my ($self) = @_;
    return $self->{c_rc};
}

sub c_uc {
    my ($self) = @_;
    return $self->{c_uc};
}

sub c_us {
    my ($self) = @_;
    return $self->{c_us};
}

sub c_ic {
    my ($self) = @_;
    return $self->{c_ic};
}

sub c_is {
    my ($self) = @_;
    return $self->{c_is};
}

sub dn {
    my ($self) = @_;
    return $self->{dn};
}

sub m0 {
    my ($self) = @_;
    return $self->{m0};
}

sub ecc {
    my ($self) = @_;
    return $self->{ecc};
}

sub sqrta {
    my ($self) = @_;
    return $self->{sqrta};
}

sub omega0 {
    my ($self) = @_;
    return $self->{omega0};
}

sub omegadot {
    my ($self) = @_;
    return $self->{omegadot};
}

sub w {
    my ($self) = @_;
    return $self->{w};
}

sub inc {
    my ($self) = @_;
    return $self->{inc};
}

sub inc_dot {
    my ($self) = @_;
    return $self->{inc_dot};
}

sub af0 {
    my ($self) = @_;
    return $self->{af0};
}

sub af1 {
    my ($self) = @_;
    return $self->{af1};
}

sub af2 {
    my ($self) = @_;
    return $self->{af2};
}

sub toc {
    my ($self) = @_;
    return $self->{toc};
}

sub iode {
    my ($self) = @_;
    return $self->{iode};
}

sub iodc {
    my ($self) = @_;
    return $self->{iodc};
}

########################################################################
package Observation::MsgObsDepB;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{header} = Observation::ObservationHeaderDep->new($self->{_io}, $self, $self->{_root});
    $self->{obs} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{obs}}, Observation::PackedObsContentDepB->new($self->{_io}, $self, $self->{_root});
    }
}

sub header {
    my ($self) = @_;
    return $self->{header};
}

sub obs {
    my ($self) = @_;
    return $self->{obs};
}

########################################################################
package Observation::PackedObsContentDepA;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{p} = $self->{_io}->read_u4le();
    $self->{l} = Observation::CarrierPhaseDepA->new($self->{_io}, $self, $self->{_root});
    $self->{cn0} = $self->{_io}->read_u1();
    $self->{lock} = $self->{_io}->read_u2le();
    $self->{prn} = $self->{_io}->read_u1();
}

sub p {
    my ($self) = @_;
    return $self->{p};
}

sub l {
    my ($self) = @_;
    return $self->{l};
}

sub cn0 {
    my ($self) = @_;
    return $self->{cn0};
}

sub lock {
    my ($self) = @_;
    return $self->{lock};
}

sub prn {
    my ($self) = @_;
    return $self->{prn};
}

########################################################################
package Observation::MsgEphemerisGlo;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{common} = Observation::EphemerisCommonContent->new($self->{_io}, $self, $self->{_root});
    $self->{gamma} = $self->{_io}->read_f4le();
    $self->{tau} = $self->{_io}->read_f4le();
    $self->{d_tau} = $self->{_io}->read_f4le();
    $self->{pos} = [];
    my $n_pos = 3;
    for (my $i = 0; $i < $n_pos; $i++) {
        push @{$self->{pos}}, $self->{_io}->read_f8le();
    }
    $self->{vel} = [];
    my $n_vel = 3;
    for (my $i = 0; $i < $n_vel; $i++) {
        push @{$self->{vel}}, $self->{_io}->read_f8le();
    }
    $self->{acc} = [];
    my $n_acc = 3;
    for (my $i = 0; $i < $n_acc; $i++) {
        push @{$self->{acc}}, $self->{_io}->read_f4le();
    }
    $self->{fcn} = $self->{_io}->read_u1();
    $self->{iod} = $self->{_io}->read_u1();
}

sub common {
    my ($self) = @_;
    return $self->{common};
}

sub gamma {
    my ($self) = @_;
    return $self->{gamma};
}

sub tau {
    my ($self) = @_;
    return $self->{tau};
}

sub d_tau {
    my ($self) = @_;
    return $self->{d_tau};
}

sub pos {
    my ($self) = @_;
    return $self->{pos};
}

sub vel {
    my ($self) = @_;
    return $self->{vel};
}

sub acc {
    my ($self) = @_;
    return $self->{acc};
}

sub fcn {
    my ($self) = @_;
    return $self->{fcn};
}

sub iod {
    my ($self) = @_;
    return $self->{iod};
}

########################################################################
package Observation::MsgIono;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{t_nmct} = Gnss::GpsTimeSec->new($self->{_io}, $self, $self->{_root});
    $self->{a0} = $self->{_io}->read_f8le();
    $self->{a1} = $self->{_io}->read_f8le();
    $self->{a2} = $self->{_io}->read_f8le();
    $self->{a3} = $self->{_io}->read_f8le();
    $self->{b0} = $self->{_io}->read_f8le();
    $self->{b1} = $self->{_io}->read_f8le();
    $self->{b2} = $self->{_io}->read_f8le();
    $self->{b3} = $self->{_io}->read_f8le();
}

sub t_nmct {
    my ($self) = @_;
    return $self->{t_nmct};
}

sub a0 {
    my ($self) = @_;
    return $self->{a0};
}

sub a1 {
    my ($self) = @_;
    return $self->{a1};
}

sub a2 {
    my ($self) = @_;
    return $self->{a2};
}

sub a3 {
    my ($self) = @_;
    return $self->{a3};
}

sub b0 {
    my ($self) = @_;
    return $self->{b0};
}

sub b1 {
    my ($self) = @_;
    return $self->{b1};
}

sub b2 {
    my ($self) = @_;
    return $self->{b2};
}

sub b3 {
    my ($self) = @_;
    return $self->{b3};
}

########################################################################
package Observation::MsgEphemerisDepD;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{tgd} = $self->{_io}->read_f8le();
    $self->{c_rs} = $self->{_io}->read_f8le();
    $self->{c_rc} = $self->{_io}->read_f8le();
    $self->{c_uc} = $self->{_io}->read_f8le();
    $self->{c_us} = $self->{_io}->read_f8le();
    $self->{c_ic} = $self->{_io}->read_f8le();
    $self->{c_is} = $self->{_io}->read_f8le();
    $self->{dn} = $self->{_io}->read_f8le();
    $self->{m0} = $self->{_io}->read_f8le();
    $self->{ecc} = $self->{_io}->read_f8le();
    $self->{sqrta} = $self->{_io}->read_f8le();
    $self->{omega0} = $self->{_io}->read_f8le();
    $self->{omegadot} = $self->{_io}->read_f8le();
    $self->{w} = $self->{_io}->read_f8le();
    $self->{inc} = $self->{_io}->read_f8le();
    $self->{inc_dot} = $self->{_io}->read_f8le();
    $self->{af0} = $self->{_io}->read_f8le();
    $self->{af1} = $self->{_io}->read_f8le();
    $self->{af2} = $self->{_io}->read_f8le();
    $self->{toe_tow} = $self->{_io}->read_f8le();
    $self->{toe_wn} = $self->{_io}->read_u2le();
    $self->{toc_tow} = $self->{_io}->read_f8le();
    $self->{toc_wn} = $self->{_io}->read_u2le();
    $self->{valid} = $self->{_io}->read_u1();
    $self->{healthy} = $self->{_io}->read_u1();
    $self->{sid} = Gnss::GnssSignalDep->new($self->{_io}, $self, $self->{_root});
    $self->{iode} = $self->{_io}->read_u1();
    $self->{iodc} = $self->{_io}->read_u2le();
    $self->{reserved} = $self->{_io}->read_u4le();
}

sub tgd {
    my ($self) = @_;
    return $self->{tgd};
}

sub c_rs {
    my ($self) = @_;
    return $self->{c_rs};
}

sub c_rc {
    my ($self) = @_;
    return $self->{c_rc};
}

sub c_uc {
    my ($self) = @_;
    return $self->{c_uc};
}

sub c_us {
    my ($self) = @_;
    return $self->{c_us};
}

sub c_ic {
    my ($self) = @_;
    return $self->{c_ic};
}

sub c_is {
    my ($self) = @_;
    return $self->{c_is};
}

sub dn {
    my ($self) = @_;
    return $self->{dn};
}

sub m0 {
    my ($self) = @_;
    return $self->{m0};
}

sub ecc {
    my ($self) = @_;
    return $self->{ecc};
}

sub sqrta {
    my ($self) = @_;
    return $self->{sqrta};
}

sub omega0 {
    my ($self) = @_;
    return $self->{omega0};
}

sub omegadot {
    my ($self) = @_;
    return $self->{omegadot};
}

sub w {
    my ($self) = @_;
    return $self->{w};
}

sub inc {
    my ($self) = @_;
    return $self->{inc};
}

sub inc_dot {
    my ($self) = @_;
    return $self->{inc_dot};
}

sub af0 {
    my ($self) = @_;
    return $self->{af0};
}

sub af1 {
    my ($self) = @_;
    return $self->{af1};
}

sub af2 {
    my ($self) = @_;
    return $self->{af2};
}

sub toe_tow {
    my ($self) = @_;
    return $self->{toe_tow};
}

sub toe_wn {
    my ($self) = @_;
    return $self->{toe_wn};
}

sub toc_tow {
    my ($self) = @_;
    return $self->{toc_tow};
}

sub toc_wn {
    my ($self) = @_;
    return $self->{toc_wn};
}

sub valid {
    my ($self) = @_;
    return $self->{valid};
}

sub healthy {
    my ($self) = @_;
    return $self->{healthy};
}

sub sid {
    my ($self) = @_;
    return $self->{sid};
}

sub iode {
    my ($self) = @_;
    return $self->{iode};
}

sub iodc {
    my ($self) = @_;
    return $self->{iodc};
}

sub reserved {
    my ($self) = @_;
    return $self->{reserved};
}

########################################################################
package Observation::MsgEphemerisGps;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{common} = Observation::EphemerisCommonContent->new($self->{_io}, $self, $self->{_root});
    $self->{tgd} = $self->{_io}->read_f4le();
    $self->{c_rs} = $self->{_io}->read_f4le();
    $self->{c_rc} = $self->{_io}->read_f4le();
    $self->{c_uc} = $self->{_io}->read_f4le();
    $self->{c_us} = $self->{_io}->read_f4le();
    $self->{c_ic} = $self->{_io}->read_f4le();
    $self->{c_is} = $self->{_io}->read_f4le();
    $self->{dn} = $self->{_io}->read_f8le();
    $self->{m0} = $self->{_io}->read_f8le();
    $self->{ecc} = $self->{_io}->read_f8le();
    $self->{sqrta} = $self->{_io}->read_f8le();
    $self->{omega0} = $self->{_io}->read_f8le();
    $self->{omegadot} = $self->{_io}->read_f8le();
    $self->{w} = $self->{_io}->read_f8le();
    $self->{inc} = $self->{_io}->read_f8le();
    $self->{inc_dot} = $self->{_io}->read_f8le();
    $self->{af0} = $self->{_io}->read_f4le();
    $self->{af1} = $self->{_io}->read_f4le();
    $self->{af2} = $self->{_io}->read_f4le();
    $self->{toc} = Gnss::GpsTimeSec->new($self->{_io}, $self, $self->{_root});
    $self->{iode} = $self->{_io}->read_u1();
    $self->{iodc} = $self->{_io}->read_u2le();
}

sub common {
    my ($self) = @_;
    return $self->{common};
}

sub tgd {
    my ($self) = @_;
    return $self->{tgd};
}

sub c_rs {
    my ($self) = @_;
    return $self->{c_rs};
}

sub c_rc {
    my ($self) = @_;
    return $self->{c_rc};
}

sub c_uc {
    my ($self) = @_;
    return $self->{c_uc};
}

sub c_us {
    my ($self) = @_;
    return $self->{c_us};
}

sub c_ic {
    my ($self) = @_;
    return $self->{c_ic};
}

sub c_is {
    my ($self) = @_;
    return $self->{c_is};
}

sub dn {
    my ($self) = @_;
    return $self->{dn};
}

sub m0 {
    my ($self) = @_;
    return $self->{m0};
}

sub ecc {
    my ($self) = @_;
    return $self->{ecc};
}

sub sqrta {
    my ($self) = @_;
    return $self->{sqrta};
}

sub omega0 {
    my ($self) = @_;
    return $self->{omega0};
}

sub omegadot {
    my ($self) = @_;
    return $self->{omegadot};
}

sub w {
    my ($self) = @_;
    return $self->{w};
}

sub inc {
    my ($self) = @_;
    return $self->{inc};
}

sub inc_dot {
    my ($self) = @_;
    return $self->{inc_dot};
}

sub af0 {
    my ($self) = @_;
    return $self->{af0};
}

sub af1 {
    my ($self) = @_;
    return $self->{af1};
}

sub af2 {
    my ($self) = @_;
    return $self->{af2};
}

sub toc {
    my ($self) = @_;
    return $self->{toc};
}

sub iode {
    my ($self) = @_;
    return $self->{iode};
}

sub iodc {
    my ($self) = @_;
    return $self->{iodc};
}

########################################################################
package Observation::MsgBasePosLlh;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{lat} = $self->{_io}->read_f8le();
    $self->{lon} = $self->{_io}->read_f8le();
    $self->{height} = $self->{_io}->read_f8le();
}

sub lat {
    my ($self) = @_;
    return $self->{lat};
}

sub lon {
    my ($self) = @_;
    return $self->{lon};
}

sub height {
    my ($self) = @_;
    return $self->{height};
}

########################################################################
package Observation::AlmanacCommonContent;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{sid} = Gnss::GnssSignal->new($self->{_io}, $self, $self->{_root});
    $self->{toa} = Gnss::GpsTimeSec->new($self->{_io}, $self, $self->{_root});
    $self->{ura} = $self->{_io}->read_f8le();
    $self->{fit_interval} = $self->{_io}->read_u4le();
    $self->{valid} = $self->{_io}->read_u1();
    $self->{health_bits} = $self->{_io}->read_u1();
}

sub sid {
    my ($self) = @_;
    return $self->{sid};
}

sub toa {
    my ($self) = @_;
    return $self->{toa};
}

sub ura {
    my ($self) = @_;
    return $self->{ura};
}

sub fit_interval {
    my ($self) = @_;
    return $self->{fit_interval};
}

sub valid {
    my ($self) = @_;
    return $self->{valid};
}

sub health_bits {
    my ($self) = @_;
    return $self->{health_bits};
}

########################################################################
package Observation::MsgOsr;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{header} = Observation::ObservationHeader->new($self->{_io}, $self, $self->{_root});
    $self->{obs} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{obs}}, Observation::PackedOsrContent->new($self->{_io}, $self, $self->{_root});
    }
}

sub header {
    my ($self) = @_;
    return $self->{header};
}

sub obs {
    my ($self) = @_;
    return $self->{obs};
}

########################################################################
package Observation::MsgEphemerisGloDepC;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{common} = Observation::EphemerisCommonContentDepB->new($self->{_io}, $self, $self->{_root});
    $self->{gamma} = $self->{_io}->read_f8le();
    $self->{tau} = $self->{_io}->read_f8le();
    $self->{d_tau} = $self->{_io}->read_f8le();
    $self->{pos} = [];
    my $n_pos = 3;
    for (my $i = 0; $i < $n_pos; $i++) {
        push @{$self->{pos}}, $self->{_io}->read_f8le();
    }
    $self->{vel} = [];
    my $n_vel = 3;
    for (my $i = 0; $i < $n_vel; $i++) {
        push @{$self->{vel}}, $self->{_io}->read_f8le();
    }
    $self->{acc} = [];
    my $n_acc = 3;
    for (my $i = 0; $i < $n_acc; $i++) {
        push @{$self->{acc}}, $self->{_io}->read_f8le();
    }
    $self->{fcn} = $self->{_io}->read_u1();
}

sub common {
    my ($self) = @_;
    return $self->{common};
}

sub gamma {
    my ($self) = @_;
    return $self->{gamma};
}

sub tau {
    my ($self) = @_;
    return $self->{tau};
}

sub d_tau {
    my ($self) = @_;
    return $self->{d_tau};
}

sub pos {
    my ($self) = @_;
    return $self->{pos};
}

sub vel {
    my ($self) = @_;
    return $self->{vel};
}

sub acc {
    my ($self) = @_;
    return $self->{acc};
}

sub fcn {
    my ($self) = @_;
    return $self->{fcn};
}

########################################################################
package Observation::MsgEphemerisGloDepB;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{common} = Observation::EphemerisCommonContentDepB->new($self->{_io}, $self, $self->{_root});
    $self->{gamma} = $self->{_io}->read_f8le();
    $self->{tau} = $self->{_io}->read_f8le();
    $self->{pos} = [];
    my $n_pos = 3;
    for (my $i = 0; $i < $n_pos; $i++) {
        push @{$self->{pos}}, $self->{_io}->read_f8le();
    }
    $self->{vel} = [];
    my $n_vel = 3;
    for (my $i = 0; $i < $n_vel; $i++) {
        push @{$self->{vel}}, $self->{_io}->read_f8le();
    }
    $self->{acc} = [];
    my $n_acc = 3;
    for (my $i = 0; $i < $n_acc; $i++) {
        push @{$self->{acc}}, $self->{_io}->read_f8le();
    }
}

sub common {
    my ($self) = @_;
    return $self->{common};
}

sub gamma {
    my ($self) = @_;
    return $self->{gamma};
}

sub tau {
    my ($self) = @_;
    return $self->{tau};
}

sub pos {
    my ($self) = @_;
    return $self->{pos};
}

sub vel {
    my ($self) = @_;
    return $self->{vel};
}

sub acc {
    my ($self) = @_;
    return $self->{acc};
}

########################################################################
package Observation::MsgSvConfigurationGpsDep;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{t_nmct} = Gnss::GpsTimeSec->new($self->{_io}, $self, $self->{_root});
    $self->{l2c_mask} = $self->{_io}->read_u4le();
}

sub t_nmct {
    my ($self) = @_;
    return $self->{t_nmct};
}

sub l2c_mask {
    my ($self) = @_;
    return $self->{l2c_mask};
}

########################################################################
package Observation::MsgEphemerisSbas;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{common} = Observation::EphemerisCommonContent->new($self->{_io}, $self, $self->{_root});
    $self->{pos} = [];
    my $n_pos = 3;
    for (my $i = 0; $i < $n_pos; $i++) {
        push @{$self->{pos}}, $self->{_io}->read_f8le();
    }
    $self->{vel} = [];
    my $n_vel = 3;
    for (my $i = 0; $i < $n_vel; $i++) {
        push @{$self->{vel}}, $self->{_io}->read_f4le();
    }
    $self->{acc} = [];
    my $n_acc = 3;
    for (my $i = 0; $i < $n_acc; $i++) {
        push @{$self->{acc}}, $self->{_io}->read_f4le();
    }
    $self->{a_gf0} = $self->{_io}->read_f4le();
    $self->{a_gf1} = $self->{_io}->read_f4le();
}

sub common {
    my ($self) = @_;
    return $self->{common};
}

sub pos {
    my ($self) = @_;
    return $self->{pos};
}

sub vel {
    my ($self) = @_;
    return $self->{vel};
}

sub acc {
    my ($self) = @_;
    return $self->{acc};
}

sub a_gf0 {
    my ($self) = @_;
    return $self->{a_gf0};
}

sub a_gf1 {
    my ($self) = @_;
    return $self->{a_gf1};
}

########################################################################
package Observation::PackedObsContentDepB;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{p} = $self->{_io}->read_u4le();
    $self->{l} = Observation::CarrierPhaseDepA->new($self->{_io}, $self, $self->{_root});
    $self->{cn0} = $self->{_io}->read_u1();
    $self->{lock} = $self->{_io}->read_u2le();
    $self->{sid} = Gnss::GnssSignalDep->new($self->{_io}, $self, $self->{_root});
}

sub p {
    my ($self) = @_;
    return $self->{p};
}

sub l {
    my ($self) = @_;
    return $self->{l};
}

sub cn0 {
    my ($self) = @_;
    return $self->{cn0};
}

sub lock {
    my ($self) = @_;
    return $self->{lock};
}

sub sid {
    my ($self) = @_;
    return $self->{sid};
}

########################################################################
package Observation::MsgObsDepC;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{header} = Observation::ObservationHeaderDep->new($self->{_io}, $self, $self->{_root});
    $self->{obs} = [];
    while (!$self->{_io}->is_eof()) {
        push @{$self->{obs}}, Observation::PackedObsContentDepC->new($self->{_io}, $self, $self->{_root});
    }
}

sub header {
    my ($self) = @_;
    return $self->{header};
}

sub obs {
    my ($self) = @_;
    return $self->{obs};
}

########################################################################
package Observation::MsgEphemerisDepA;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{tgd} = $self->{_io}->read_f8le();
    $self->{c_rs} = $self->{_io}->read_f8le();
    $self->{c_rc} = $self->{_io}->read_f8le();
    $self->{c_uc} = $self->{_io}->read_f8le();
    $self->{c_us} = $self->{_io}->read_f8le();
    $self->{c_ic} = $self->{_io}->read_f8le();
    $self->{c_is} = $self->{_io}->read_f8le();
    $self->{dn} = $self->{_io}->read_f8le();
    $self->{m0} = $self->{_io}->read_f8le();
    $self->{ecc} = $self->{_io}->read_f8le();
    $self->{sqrta} = $self->{_io}->read_f8le();
    $self->{omega0} = $self->{_io}->read_f8le();
    $self->{omegadot} = $self->{_io}->read_f8le();
    $self->{w} = $self->{_io}->read_f8le();
    $self->{inc} = $self->{_io}->read_f8le();
    $self->{inc_dot} = $self->{_io}->read_f8le();
    $self->{af0} = $self->{_io}->read_f8le();
    $self->{af1} = $self->{_io}->read_f8le();
    $self->{af2} = $self->{_io}->read_f8le();
    $self->{toe_tow} = $self->{_io}->read_f8le();
    $self->{toe_wn} = $self->{_io}->read_u2le();
    $self->{toc_tow} = $self->{_io}->read_f8le();
    $self->{toc_wn} = $self->{_io}->read_u2le();
    $self->{valid} = $self->{_io}->read_u1();
    $self->{healthy} = $self->{_io}->read_u1();
    $self->{prn} = $self->{_io}->read_u1();
}

sub tgd {
    my ($self) = @_;
    return $self->{tgd};
}

sub c_rs {
    my ($self) = @_;
    return $self->{c_rs};
}

sub c_rc {
    my ($self) = @_;
    return $self->{c_rc};
}

sub c_uc {
    my ($self) = @_;
    return $self->{c_uc};
}

sub c_us {
    my ($self) = @_;
    return $self->{c_us};
}

sub c_ic {
    my ($self) = @_;
    return $self->{c_ic};
}

sub c_is {
    my ($self) = @_;
    return $self->{c_is};
}

sub dn {
    my ($self) = @_;
    return $self->{dn};
}

sub m0 {
    my ($self) = @_;
    return $self->{m0};
}

sub ecc {
    my ($self) = @_;
    return $self->{ecc};
}

sub sqrta {
    my ($self) = @_;
    return $self->{sqrta};
}

sub omega0 {
    my ($self) = @_;
    return $self->{omega0};
}

sub omegadot {
    my ($self) = @_;
    return $self->{omegadot};
}

sub w {
    my ($self) = @_;
    return $self->{w};
}

sub inc {
    my ($self) = @_;
    return $self->{inc};
}

sub inc_dot {
    my ($self) = @_;
    return $self->{inc_dot};
}

sub af0 {
    my ($self) = @_;
    return $self->{af0};
}

sub af1 {
    my ($self) = @_;
    return $self->{af1};
}

sub af2 {
    my ($self) = @_;
    return $self->{af2};
}

sub toe_tow {
    my ($self) = @_;
    return $self->{toe_tow};
}

sub toe_wn {
    my ($self) = @_;
    return $self->{toe_wn};
}

sub toc_tow {
    my ($self) = @_;
    return $self->{toc_tow};
}

sub toc_wn {
    my ($self) = @_;
    return $self->{toc_wn};
}

sub valid {
    my ($self) = @_;
    return $self->{valid};
}

sub healthy {
    my ($self) = @_;
    return $self->{healthy};
}

sub prn {
    my ($self) = @_;
    return $self->{prn};
}

########################################################################
package Observation::EphemerisCommonContentDepB;

our @ISA = 'IO::KaitaiStruct::Struct';

sub from_file {
    my ($class, $filename) = @_;
    my $fd;

    open($fd, '<', $filename) or return undef;
    binmode($fd);
    return new($class, IO::KaitaiStruct::Stream->new($fd));
}

sub new {
    my ($class, $_io, $_parent, $_root) = @_;
    my $self = IO::KaitaiStruct::Struct->new($_io);

    bless $self, $class;
    $self->{_parent} = $_parent;
    $self->{_root} = $_root || $self;;

    $self->_read();

    return $self;
}

sub _read {
    my ($self) = @_;

    $self->{sid} = Gnss::GnssSignal->new($self->{_io}, $self, $self->{_root});
    $self->{toe} = Gnss::GpsTimeSec->new($self->{_io}, $self, $self->{_root});
    $self->{ura} = $self->{_io}->read_f8le();
    $self->{fit_interval} = $self->{_io}->read_u4le();
    $self->{valid} = $self->{_io}->read_u1();
    $self->{health_bits} = $self->{_io}->read_u1();
}

sub sid {
    my ($self) = @_;
    return $self->{sid};
}

sub toe {
    my ($self) = @_;
    return $self->{toe};
}

sub ura {
    my ($self) = @_;
    return $self->{ura};
}

sub fit_interval {
    my ($self) = @_;
    return $self->{fit_interval};
}

sub valid {
    my ($self) = @_;
    return $self->{valid};
}

sub health_bits {
    my ($self) = @_;
    return $self->{health_bits};
}

1;
