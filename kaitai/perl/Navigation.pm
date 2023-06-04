# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

use strict;
use warnings;
use IO::KaitaiStruct 0.009_000;
use Encode;

########################################################################
package Navigation;

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
package Navigation::MsgPosLlhDepA;

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

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{lat} = $self->{_io}->read_f8le();
    $self->{lon} = $self->{_io}->read_f8le();
    $self->{height} = $self->{_io}->read_f8le();
    $self->{h_accuracy} = $self->{_io}->read_u2le();
    $self->{v_accuracy} = $self->{_io}->read_u2le();
    $self->{n_sats} = $self->{_io}->read_u1();
    $self->{flags} = $self->{_io}->read_u1();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
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

sub h_accuracy {
    my ($self) = @_;
    return $self->{h_accuracy};
}

sub v_accuracy {
    my ($self) = @_;
    return $self->{v_accuracy};
}

sub n_sats {
    my ($self) = @_;
    return $self->{n_sats};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Navigation::MsgProtectionLevelDepA;

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

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{vpl} = $self->{_io}->read_u2le();
    $self->{hpl} = $self->{_io}->read_u2le();
    $self->{lat} = $self->{_io}->read_f8le();
    $self->{lon} = $self->{_io}->read_f8le();
    $self->{height} = $self->{_io}->read_f8le();
    $self->{flags} = $self->{_io}->read_u1();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
}

sub vpl {
    my ($self) = @_;
    return $self->{vpl};
}

sub hpl {
    my ($self) = @_;
    return $self->{hpl};
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

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Navigation::MsgPosLlhCov;

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

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{lat} = $self->{_io}->read_f8le();
    $self->{lon} = $self->{_io}->read_f8le();
    $self->{height} = $self->{_io}->read_f8le();
    $self->{cov_n_n} = $self->{_io}->read_f4le();
    $self->{cov_n_e} = $self->{_io}->read_f4le();
    $self->{cov_n_d} = $self->{_io}->read_f4le();
    $self->{cov_e_e} = $self->{_io}->read_f4le();
    $self->{cov_e_d} = $self->{_io}->read_f4le();
    $self->{cov_d_d} = $self->{_io}->read_f4le();
    $self->{n_sats} = $self->{_io}->read_u1();
    $self->{flags} = $self->{_io}->read_u1();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
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

sub cov_n_n {
    my ($self) = @_;
    return $self->{cov_n_n};
}

sub cov_n_e {
    my ($self) = @_;
    return $self->{cov_n_e};
}

sub cov_n_d {
    my ($self) = @_;
    return $self->{cov_n_d};
}

sub cov_e_e {
    my ($self) = @_;
    return $self->{cov_e_e};
}

sub cov_e_d {
    my ($self) = @_;
    return $self->{cov_e_d};
}

sub cov_d_d {
    my ($self) = @_;
    return $self->{cov_d_d};
}

sub n_sats {
    my ($self) = @_;
    return $self->{n_sats};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Navigation::MsgVelNedDepA;

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

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{n} = $self->{_io}->read_s4le();
    $self->{e} = $self->{_io}->read_s4le();
    $self->{d} = $self->{_io}->read_s4le();
    $self->{h_accuracy} = $self->{_io}->read_u2le();
    $self->{v_accuracy} = $self->{_io}->read_u2le();
    $self->{n_sats} = $self->{_io}->read_u1();
    $self->{flags} = $self->{_io}->read_u1();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
}

sub n {
    my ($self) = @_;
    return $self->{n};
}

sub e {
    my ($self) = @_;
    return $self->{e};
}

sub d {
    my ($self) = @_;
    return $self->{d};
}

sub h_accuracy {
    my ($self) = @_;
    return $self->{h_accuracy};
}

sub v_accuracy {
    my ($self) = @_;
    return $self->{v_accuracy};
}

sub n_sats {
    my ($self) = @_;
    return $self->{n_sats};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Navigation::MsgVelNedCov;

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

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{n} = $self->{_io}->read_s4le();
    $self->{e} = $self->{_io}->read_s4le();
    $self->{d} = $self->{_io}->read_s4le();
    $self->{cov_n_n} = $self->{_io}->read_f4le();
    $self->{cov_n_e} = $self->{_io}->read_f4le();
    $self->{cov_n_d} = $self->{_io}->read_f4le();
    $self->{cov_e_e} = $self->{_io}->read_f4le();
    $self->{cov_e_d} = $self->{_io}->read_f4le();
    $self->{cov_d_d} = $self->{_io}->read_f4le();
    $self->{n_sats} = $self->{_io}->read_u1();
    $self->{flags} = $self->{_io}->read_u1();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
}

sub n {
    my ($self) = @_;
    return $self->{n};
}

sub e {
    my ($self) = @_;
    return $self->{e};
}

sub d {
    my ($self) = @_;
    return $self->{d};
}

sub cov_n_n {
    my ($self) = @_;
    return $self->{cov_n_n};
}

sub cov_n_e {
    my ($self) = @_;
    return $self->{cov_n_e};
}

sub cov_n_d {
    my ($self) = @_;
    return $self->{cov_n_d};
}

sub cov_e_e {
    my ($self) = @_;
    return $self->{cov_e_e};
}

sub cov_e_d {
    my ($self) = @_;
    return $self->{cov_e_d};
}

sub cov_d_d {
    my ($self) = @_;
    return $self->{cov_d_d};
}

sub n_sats {
    my ($self) = @_;
    return $self->{n_sats};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Navigation::MsgUtcTime;

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

    $self->{flags} = $self->{_io}->read_u1();
    $self->{tow} = $self->{_io}->read_u4le();
    $self->{year} = $self->{_io}->read_u2le();
    $self->{month} = $self->{_io}->read_u1();
    $self->{day} = $self->{_io}->read_u1();
    $self->{hours} = $self->{_io}->read_u1();
    $self->{minutes} = $self->{_io}->read_u1();
    $self->{seconds} = $self->{_io}->read_u1();
    $self->{ns} = $self->{_io}->read_u4le();
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
}

sub year {
    my ($self) = @_;
    return $self->{year};
}

sub month {
    my ($self) = @_;
    return $self->{month};
}

sub day {
    my ($self) = @_;
    return $self->{day};
}

sub hours {
    my ($self) = @_;
    return $self->{hours};
}

sub minutes {
    my ($self) = @_;
    return $self->{minutes};
}

sub seconds {
    my ($self) = @_;
    return $self->{seconds};
}

sub ns {
    my ($self) = @_;
    return $self->{ns};
}

########################################################################
package Navigation::MsgPosEcefCovGnss;

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

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{x} = $self->{_io}->read_f8le();
    $self->{y} = $self->{_io}->read_f8le();
    $self->{z} = $self->{_io}->read_f8le();
    $self->{cov_x_x} = $self->{_io}->read_f4le();
    $self->{cov_x_y} = $self->{_io}->read_f4le();
    $self->{cov_x_z} = $self->{_io}->read_f4le();
    $self->{cov_y_y} = $self->{_io}->read_f4le();
    $self->{cov_y_z} = $self->{_io}->read_f4le();
    $self->{cov_z_z} = $self->{_io}->read_f4le();
    $self->{n_sats} = $self->{_io}->read_u1();
    $self->{flags} = $self->{_io}->read_u1();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
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

sub cov_x_x {
    my ($self) = @_;
    return $self->{cov_x_x};
}

sub cov_x_y {
    my ($self) = @_;
    return $self->{cov_x_y};
}

sub cov_x_z {
    my ($self) = @_;
    return $self->{cov_x_z};
}

sub cov_y_y {
    my ($self) = @_;
    return $self->{cov_y_y};
}

sub cov_y_z {
    my ($self) = @_;
    return $self->{cov_y_z};
}

sub cov_z_z {
    my ($self) = @_;
    return $self->{cov_z_z};
}

sub n_sats {
    my ($self) = @_;
    return $self->{n_sats};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Navigation::MsgVelNedGnss;

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

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{n} = $self->{_io}->read_s4le();
    $self->{e} = $self->{_io}->read_s4le();
    $self->{d} = $self->{_io}->read_s4le();
    $self->{h_accuracy} = $self->{_io}->read_u2le();
    $self->{v_accuracy} = $self->{_io}->read_u2le();
    $self->{n_sats} = $self->{_io}->read_u1();
    $self->{flags} = $self->{_io}->read_u1();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
}

sub n {
    my ($self) = @_;
    return $self->{n};
}

sub e {
    my ($self) = @_;
    return $self->{e};
}

sub d {
    my ($self) = @_;
    return $self->{d};
}

sub h_accuracy {
    my ($self) = @_;
    return $self->{h_accuracy};
}

sub v_accuracy {
    my ($self) = @_;
    return $self->{v_accuracy};
}

sub n_sats {
    my ($self) = @_;
    return $self->{n_sats};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Navigation::MsgVelNedCovGnss;

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

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{n} = $self->{_io}->read_s4le();
    $self->{e} = $self->{_io}->read_s4le();
    $self->{d} = $self->{_io}->read_s4le();
    $self->{cov_n_n} = $self->{_io}->read_f4le();
    $self->{cov_n_e} = $self->{_io}->read_f4le();
    $self->{cov_n_d} = $self->{_io}->read_f4le();
    $self->{cov_e_e} = $self->{_io}->read_f4le();
    $self->{cov_e_d} = $self->{_io}->read_f4le();
    $self->{cov_d_d} = $self->{_io}->read_f4le();
    $self->{n_sats} = $self->{_io}->read_u1();
    $self->{flags} = $self->{_io}->read_u1();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
}

sub n {
    my ($self) = @_;
    return $self->{n};
}

sub e {
    my ($self) = @_;
    return $self->{e};
}

sub d {
    my ($self) = @_;
    return $self->{d};
}

sub cov_n_n {
    my ($self) = @_;
    return $self->{cov_n_n};
}

sub cov_n_e {
    my ($self) = @_;
    return $self->{cov_n_e};
}

sub cov_n_d {
    my ($self) = @_;
    return $self->{cov_n_d};
}

sub cov_e_e {
    my ($self) = @_;
    return $self->{cov_e_e};
}

sub cov_e_d {
    my ($self) = @_;
    return $self->{cov_e_d};
}

sub cov_d_d {
    my ($self) = @_;
    return $self->{cov_d_d};
}

sub n_sats {
    my ($self) = @_;
    return $self->{n_sats};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Navigation::MsgBaselineNedDepA;

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

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{n} = $self->{_io}->read_s4le();
    $self->{e} = $self->{_io}->read_s4le();
    $self->{d} = $self->{_io}->read_s4le();
    $self->{h_accuracy} = $self->{_io}->read_u2le();
    $self->{v_accuracy} = $self->{_io}->read_u2le();
    $self->{n_sats} = $self->{_io}->read_u1();
    $self->{flags} = $self->{_io}->read_u1();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
}

sub n {
    my ($self) = @_;
    return $self->{n};
}

sub e {
    my ($self) = @_;
    return $self->{e};
}

sub d {
    my ($self) = @_;
    return $self->{d};
}

sub h_accuracy {
    my ($self) = @_;
    return $self->{h_accuracy};
}

sub v_accuracy {
    my ($self) = @_;
    return $self->{v_accuracy};
}

sub n_sats {
    my ($self) = @_;
    return $self->{n_sats};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Navigation::MsgVelEcefDepA;

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

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{x} = $self->{_io}->read_s4le();
    $self->{y} = $self->{_io}->read_s4le();
    $self->{z} = $self->{_io}->read_s4le();
    $self->{accuracy} = $self->{_io}->read_u2le();
    $self->{n_sats} = $self->{_io}->read_u1();
    $self->{flags} = $self->{_io}->read_u1();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
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

sub accuracy {
    my ($self) = @_;
    return $self->{accuracy};
}

sub n_sats {
    my ($self) = @_;
    return $self->{n_sats};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Navigation::MsgReferenceFrameParam;

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

    $self->{ssr_iod} = $self->{_io}->read_u1();
    $self->{sn} = Encode::decode("ascii", $self->{_io}->read_bytes(32));
    $self->{tn} = Encode::decode("ascii", $self->{_io}->read_bytes(32));
    $self->{sin} = $self->{_io}->read_u1();
    $self->{utn} = $self->{_io}->read_u2le();
    $self->{re_t0} = $self->{_io}->read_u2le();
    $self->{delta_x0} = $self->{_io}->read_s4le();
    $self->{delta_y0} = $self->{_io}->read_s4le();
    $self->{delta_z0} = $self->{_io}->read_s4le();
    $self->{theta_01} = $self->{_io}->read_s4le();
    $self->{theta_02} = $self->{_io}->read_s4le();
    $self->{theta_03} = $self->{_io}->read_s4le();
    $self->{scale} = $self->{_io}->read_s4le();
    $self->{dot_delta_x0} = $self->{_io}->read_s4le();
    $self->{dot_delta_y0} = $self->{_io}->read_s4le();
    $self->{dot_delta_z0} = $self->{_io}->read_s4le();
    $self->{dot_theta_01} = $self->{_io}->read_s4le();
    $self->{dot_theta_02} = $self->{_io}->read_s4le();
    $self->{dot_theta_03} = $self->{_io}->read_s4le();
    $self->{dot_scale} = $self->{_io}->read_s2le();
}

sub ssr_iod {
    my ($self) = @_;
    return $self->{ssr_iod};
}

sub sn {
    my ($self) = @_;
    return $self->{sn};
}

sub tn {
    my ($self) = @_;
    return $self->{tn};
}

sub sin {
    my ($self) = @_;
    return $self->{sin};
}

sub utn {
    my ($self) = @_;
    return $self->{utn};
}

sub re_t0 {
    my ($self) = @_;
    return $self->{re_t0};
}

sub delta_x0 {
    my ($self) = @_;
    return $self->{delta_x0};
}

sub delta_y0 {
    my ($self) = @_;
    return $self->{delta_y0};
}

sub delta_z0 {
    my ($self) = @_;
    return $self->{delta_z0};
}

sub theta_01 {
    my ($self) = @_;
    return $self->{theta_01};
}

sub theta_02 {
    my ($self) = @_;
    return $self->{theta_02};
}

sub theta_03 {
    my ($self) = @_;
    return $self->{theta_03};
}

sub scale {
    my ($self) = @_;
    return $self->{scale};
}

sub dot_delta_x0 {
    my ($self) = @_;
    return $self->{dot_delta_x0};
}

sub dot_delta_y0 {
    my ($self) = @_;
    return $self->{dot_delta_y0};
}

sub dot_delta_z0 {
    my ($self) = @_;
    return $self->{dot_delta_z0};
}

sub dot_theta_01 {
    my ($self) = @_;
    return $self->{dot_theta_01};
}

sub dot_theta_02 {
    my ($self) = @_;
    return $self->{dot_theta_02};
}

sub dot_theta_03 {
    my ($self) = @_;
    return $self->{dot_theta_03};
}

sub dot_scale {
    my ($self) = @_;
    return $self->{dot_scale};
}

########################################################################
package Navigation::MsgPoseRelative;

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

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{sensor_id} = $self->{_io}->read_u1();
    $self->{timestamp_1} = $self->{_io}->read_u4le();
    $self->{timestamp_2} = $self->{_io}->read_u4le();
    $self->{trans} = [];
    my $n_trans = 3;
    for (my $i = 0; $i < $n_trans; $i++) {
        push @{$self->{trans}}, $self->{_io}->read_s4le();
    }
    $self->{w} = $self->{_io}->read_s4le();
    $self->{x} = $self->{_io}->read_s4le();
    $self->{y} = $self->{_io}->read_s4le();
    $self->{z} = $self->{_io}->read_s4le();
    $self->{cov_r_x_x} = $self->{_io}->read_f4le();
    $self->{cov_r_x_y} = $self->{_io}->read_f4le();
    $self->{cov_r_x_z} = $self->{_io}->read_f4le();
    $self->{cov_r_y_y} = $self->{_io}->read_f4le();
    $self->{cov_r_y_z} = $self->{_io}->read_f4le();
    $self->{cov_r_z_z} = $self->{_io}->read_f4le();
    $self->{cov_c_x_x} = $self->{_io}->read_f4le();
    $self->{cov_c_x_y} = $self->{_io}->read_f4le();
    $self->{cov_c_x_z} = $self->{_io}->read_f4le();
    $self->{cov_c_y_y} = $self->{_io}->read_f4le();
    $self->{cov_c_y_z} = $self->{_io}->read_f4le();
    $self->{cov_c_z_z} = $self->{_io}->read_f4le();
    $self->{flags} = $self->{_io}->read_u1();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
}

sub sensor_id {
    my ($self) = @_;
    return $self->{sensor_id};
}

sub timestamp_1 {
    my ($self) = @_;
    return $self->{timestamp_1};
}

sub timestamp_2 {
    my ($self) = @_;
    return $self->{timestamp_2};
}

sub trans {
    my ($self) = @_;
    return $self->{trans};
}

sub w {
    my ($self) = @_;
    return $self->{w};
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

sub cov_r_x_x {
    my ($self) = @_;
    return $self->{cov_r_x_x};
}

sub cov_r_x_y {
    my ($self) = @_;
    return $self->{cov_r_x_y};
}

sub cov_r_x_z {
    my ($self) = @_;
    return $self->{cov_r_x_z};
}

sub cov_r_y_y {
    my ($self) = @_;
    return $self->{cov_r_y_y};
}

sub cov_r_y_z {
    my ($self) = @_;
    return $self->{cov_r_y_z};
}

sub cov_r_z_z {
    my ($self) = @_;
    return $self->{cov_r_z_z};
}

sub cov_c_x_x {
    my ($self) = @_;
    return $self->{cov_c_x_x};
}

sub cov_c_x_y {
    my ($self) = @_;
    return $self->{cov_c_x_y};
}

sub cov_c_x_z {
    my ($self) = @_;
    return $self->{cov_c_x_z};
}

sub cov_c_y_y {
    my ($self) = @_;
    return $self->{cov_c_y_y};
}

sub cov_c_y_z {
    my ($self) = @_;
    return $self->{cov_c_y_z};
}

sub cov_c_z_z {
    my ($self) = @_;
    return $self->{cov_c_z_z};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Navigation::MsgVelEcefCov;

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

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{x} = $self->{_io}->read_s4le();
    $self->{y} = $self->{_io}->read_s4le();
    $self->{z} = $self->{_io}->read_s4le();
    $self->{cov_x_x} = $self->{_io}->read_f4le();
    $self->{cov_x_y} = $self->{_io}->read_f4le();
    $self->{cov_x_z} = $self->{_io}->read_f4le();
    $self->{cov_y_y} = $self->{_io}->read_f4le();
    $self->{cov_y_z} = $self->{_io}->read_f4le();
    $self->{cov_z_z} = $self->{_io}->read_f4le();
    $self->{n_sats} = $self->{_io}->read_u1();
    $self->{flags} = $self->{_io}->read_u1();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
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

sub cov_x_x {
    my ($self) = @_;
    return $self->{cov_x_x};
}

sub cov_x_y {
    my ($self) = @_;
    return $self->{cov_x_y};
}

sub cov_x_z {
    my ($self) = @_;
    return $self->{cov_x_z};
}

sub cov_y_y {
    my ($self) = @_;
    return $self->{cov_y_y};
}

sub cov_y_z {
    my ($self) = @_;
    return $self->{cov_y_z};
}

sub cov_z_z {
    my ($self) = @_;
    return $self->{cov_z_z};
}

sub n_sats {
    my ($self) = @_;
    return $self->{n_sats};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Navigation::MsgVelBody;

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

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{x} = $self->{_io}->read_s4le();
    $self->{y} = $self->{_io}->read_s4le();
    $self->{z} = $self->{_io}->read_s4le();
    $self->{cov_x_x} = $self->{_io}->read_f4le();
    $self->{cov_x_y} = $self->{_io}->read_f4le();
    $self->{cov_x_z} = $self->{_io}->read_f4le();
    $self->{cov_y_y} = $self->{_io}->read_f4le();
    $self->{cov_y_z} = $self->{_io}->read_f4le();
    $self->{cov_z_z} = $self->{_io}->read_f4le();
    $self->{n_sats} = $self->{_io}->read_u1();
    $self->{flags} = $self->{_io}->read_u1();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
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

sub cov_x_x {
    my ($self) = @_;
    return $self->{cov_x_x};
}

sub cov_x_y {
    my ($self) = @_;
    return $self->{cov_x_y};
}

sub cov_x_z {
    my ($self) = @_;
    return $self->{cov_x_z};
}

sub cov_y_y {
    my ($self) = @_;
    return $self->{cov_y_y};
}

sub cov_y_z {
    my ($self) = @_;
    return $self->{cov_y_z};
}

sub cov_z_z {
    my ($self) = @_;
    return $self->{cov_z_z};
}

sub n_sats {
    my ($self) = @_;
    return $self->{n_sats};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Navigation::MsgVelEcefGnss;

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

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{x} = $self->{_io}->read_s4le();
    $self->{y} = $self->{_io}->read_s4le();
    $self->{z} = $self->{_io}->read_s4le();
    $self->{accuracy} = $self->{_io}->read_u2le();
    $self->{n_sats} = $self->{_io}->read_u1();
    $self->{flags} = $self->{_io}->read_u1();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
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

sub accuracy {
    my ($self) = @_;
    return $self->{accuracy};
}

sub n_sats {
    my ($self) = @_;
    return $self->{n_sats};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Navigation::MsgVelEcef;

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

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{x} = $self->{_io}->read_s4le();
    $self->{y} = $self->{_io}->read_s4le();
    $self->{z} = $self->{_io}->read_s4le();
    $self->{accuracy} = $self->{_io}->read_u2le();
    $self->{n_sats} = $self->{_io}->read_u1();
    $self->{flags} = $self->{_io}->read_u1();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
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

sub accuracy {
    my ($self) = @_;
    return $self->{accuracy};
}

sub n_sats {
    my ($self) = @_;
    return $self->{n_sats};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Navigation::MsgPosLlhCovGnss;

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

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{lat} = $self->{_io}->read_f8le();
    $self->{lon} = $self->{_io}->read_f8le();
    $self->{height} = $self->{_io}->read_f8le();
    $self->{cov_n_n} = $self->{_io}->read_f4le();
    $self->{cov_n_e} = $self->{_io}->read_f4le();
    $self->{cov_n_d} = $self->{_io}->read_f4le();
    $self->{cov_e_e} = $self->{_io}->read_f4le();
    $self->{cov_e_d} = $self->{_io}->read_f4le();
    $self->{cov_d_d} = $self->{_io}->read_f4le();
    $self->{n_sats} = $self->{_io}->read_u1();
    $self->{flags} = $self->{_io}->read_u1();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
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

sub cov_n_n {
    my ($self) = @_;
    return $self->{cov_n_n};
}

sub cov_n_e {
    my ($self) = @_;
    return $self->{cov_n_e};
}

sub cov_n_d {
    my ($self) = @_;
    return $self->{cov_n_d};
}

sub cov_e_e {
    my ($self) = @_;
    return $self->{cov_e_e};
}

sub cov_e_d {
    my ($self) = @_;
    return $self->{cov_e_d};
}

sub cov_d_d {
    my ($self) = @_;
    return $self->{cov_d_d};
}

sub n_sats {
    my ($self) = @_;
    return $self->{n_sats};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Navigation::MsgBaselineEcef;

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

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{x} = $self->{_io}->read_s4le();
    $self->{y} = $self->{_io}->read_s4le();
    $self->{z} = $self->{_io}->read_s4le();
    $self->{accuracy} = $self->{_io}->read_u2le();
    $self->{n_sats} = $self->{_io}->read_u1();
    $self->{flags} = $self->{_io}->read_u1();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
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

sub accuracy {
    my ($self) = @_;
    return $self->{accuracy};
}

sub n_sats {
    my ($self) = @_;
    return $self->{n_sats};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Navigation::MsgDopsDepA;

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

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{gdop} = $self->{_io}->read_u2le();
    $self->{pdop} = $self->{_io}->read_u2le();
    $self->{tdop} = $self->{_io}->read_u2le();
    $self->{hdop} = $self->{_io}->read_u2le();
    $self->{vdop} = $self->{_io}->read_u2le();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
}

sub gdop {
    my ($self) = @_;
    return $self->{gdop};
}

sub pdop {
    my ($self) = @_;
    return $self->{pdop};
}

sub tdop {
    my ($self) = @_;
    return $self->{tdop};
}

sub hdop {
    my ($self) = @_;
    return $self->{hdop};
}

sub vdop {
    my ($self) = @_;
    return $self->{vdop};
}

########################################################################
package Navigation::MsgPosEcef;

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

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{x} = $self->{_io}->read_f8le();
    $self->{y} = $self->{_io}->read_f8le();
    $self->{z} = $self->{_io}->read_f8le();
    $self->{accuracy} = $self->{_io}->read_u2le();
    $self->{n_sats} = $self->{_io}->read_u1();
    $self->{flags} = $self->{_io}->read_u1();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
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

sub accuracy {
    my ($self) = @_;
    return $self->{accuracy};
}

sub n_sats {
    my ($self) = @_;
    return $self->{n_sats};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Navigation::MsgAgeCorrections;

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

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{age} = $self->{_io}->read_u2le();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
}

sub age {
    my ($self) = @_;
    return $self->{age};
}

########################################################################
package Navigation::MsgVelEcefCovGnss;

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

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{x} = $self->{_io}->read_s4le();
    $self->{y} = $self->{_io}->read_s4le();
    $self->{z} = $self->{_io}->read_s4le();
    $self->{cov_x_x} = $self->{_io}->read_f4le();
    $self->{cov_x_y} = $self->{_io}->read_f4le();
    $self->{cov_x_z} = $self->{_io}->read_f4le();
    $self->{cov_y_y} = $self->{_io}->read_f4le();
    $self->{cov_y_z} = $self->{_io}->read_f4le();
    $self->{cov_z_z} = $self->{_io}->read_f4le();
    $self->{n_sats} = $self->{_io}->read_u1();
    $self->{flags} = $self->{_io}->read_u1();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
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

sub cov_x_x {
    my ($self) = @_;
    return $self->{cov_x_x};
}

sub cov_x_y {
    my ($self) = @_;
    return $self->{cov_x_y};
}

sub cov_x_z {
    my ($self) = @_;
    return $self->{cov_x_z};
}

sub cov_y_y {
    my ($self) = @_;
    return $self->{cov_y_y};
}

sub cov_y_z {
    my ($self) = @_;
    return $self->{cov_y_z};
}

sub cov_z_z {
    my ($self) = @_;
    return $self->{cov_z_z};
}

sub n_sats {
    my ($self) = @_;
    return $self->{n_sats};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Navigation::MsgProtectionLevel;

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

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{wn} = $self->{_io}->read_s2le();
    $self->{hpl} = $self->{_io}->read_u2le();
    $self->{vpl} = $self->{_io}->read_u2le();
    $self->{atpl} = $self->{_io}->read_u2le();
    $self->{ctpl} = $self->{_io}->read_u2le();
    $self->{hvpl} = $self->{_io}->read_u2le();
    $self->{vvpl} = $self->{_io}->read_u2le();
    $self->{hopl} = $self->{_io}->read_u2le();
    $self->{popl} = $self->{_io}->read_u2le();
    $self->{ropl} = $self->{_io}->read_u2le();
    $self->{lat} = $self->{_io}->read_f8le();
    $self->{lon} = $self->{_io}->read_f8le();
    $self->{height} = $self->{_io}->read_f8le();
    $self->{v_x} = $self->{_io}->read_s4le();
    $self->{v_y} = $self->{_io}->read_s4le();
    $self->{v_z} = $self->{_io}->read_s4le();
    $self->{roll} = $self->{_io}->read_s4le();
    $self->{pitch} = $self->{_io}->read_s4le();
    $self->{heading} = $self->{_io}->read_s4le();
    $self->{flags} = $self->{_io}->read_u4le();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
}

sub wn {
    my ($self) = @_;
    return $self->{wn};
}

sub hpl {
    my ($self) = @_;
    return $self->{hpl};
}

sub vpl {
    my ($self) = @_;
    return $self->{vpl};
}

sub atpl {
    my ($self) = @_;
    return $self->{atpl};
}

sub ctpl {
    my ($self) = @_;
    return $self->{ctpl};
}

sub hvpl {
    my ($self) = @_;
    return $self->{hvpl};
}

sub vvpl {
    my ($self) = @_;
    return $self->{vvpl};
}

sub hopl {
    my ($self) = @_;
    return $self->{hopl};
}

sub popl {
    my ($self) = @_;
    return $self->{popl};
}

sub ropl {
    my ($self) = @_;
    return $self->{ropl};
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

sub v_x {
    my ($self) = @_;
    return $self->{v_x};
}

sub v_y {
    my ($self) = @_;
    return $self->{v_y};
}

sub v_z {
    my ($self) = @_;
    return $self->{v_z};
}

sub roll {
    my ($self) = @_;
    return $self->{roll};
}

sub pitch {
    my ($self) = @_;
    return $self->{pitch};
}

sub heading {
    my ($self) = @_;
    return $self->{heading};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Navigation::MsgPosEcefCov;

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

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{x} = $self->{_io}->read_f8le();
    $self->{y} = $self->{_io}->read_f8le();
    $self->{z} = $self->{_io}->read_f8le();
    $self->{cov_x_x} = $self->{_io}->read_f4le();
    $self->{cov_x_y} = $self->{_io}->read_f4le();
    $self->{cov_x_z} = $self->{_io}->read_f4le();
    $self->{cov_y_y} = $self->{_io}->read_f4le();
    $self->{cov_y_z} = $self->{_io}->read_f4le();
    $self->{cov_z_z} = $self->{_io}->read_f4le();
    $self->{n_sats} = $self->{_io}->read_u1();
    $self->{flags} = $self->{_io}->read_u1();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
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

sub cov_x_x {
    my ($self) = @_;
    return $self->{cov_x_x};
}

sub cov_x_y {
    my ($self) = @_;
    return $self->{cov_x_y};
}

sub cov_x_z {
    my ($self) = @_;
    return $self->{cov_x_z};
}

sub cov_y_y {
    my ($self) = @_;
    return $self->{cov_y_y};
}

sub cov_y_z {
    my ($self) = @_;
    return $self->{cov_y_z};
}

sub cov_z_z {
    my ($self) = @_;
    return $self->{cov_z_z};
}

sub n_sats {
    my ($self) = @_;
    return $self->{n_sats};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Navigation::MsgPosEcefGnss;

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

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{x} = $self->{_io}->read_f8le();
    $self->{y} = $self->{_io}->read_f8le();
    $self->{z} = $self->{_io}->read_f8le();
    $self->{accuracy} = $self->{_io}->read_u2le();
    $self->{n_sats} = $self->{_io}->read_u1();
    $self->{flags} = $self->{_io}->read_u1();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
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

sub accuracy {
    my ($self) = @_;
    return $self->{accuracy};
}

sub n_sats {
    my ($self) = @_;
    return $self->{n_sats};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Navigation::MsgVelNed;

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

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{n} = $self->{_io}->read_s4le();
    $self->{e} = $self->{_io}->read_s4le();
    $self->{d} = $self->{_io}->read_s4le();
    $self->{h_accuracy} = $self->{_io}->read_u2le();
    $self->{v_accuracy} = $self->{_io}->read_u2le();
    $self->{n_sats} = $self->{_io}->read_u1();
    $self->{flags} = $self->{_io}->read_u1();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
}

sub n {
    my ($self) = @_;
    return $self->{n};
}

sub e {
    my ($self) = @_;
    return $self->{e};
}

sub d {
    my ($self) = @_;
    return $self->{d};
}

sub h_accuracy {
    my ($self) = @_;
    return $self->{h_accuracy};
}

sub v_accuracy {
    my ($self) = @_;
    return $self->{v_accuracy};
}

sub n_sats {
    my ($self) = @_;
    return $self->{n_sats};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Navigation::MsgUtcLeapSecond;

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

    $self->{reserved_0} = $self->{_io}->read_s2le();
    $self->{reserved_1} = $self->{_io}->read_s2le();
    $self->{reserved_2} = $self->{_io}->read_s1();
    $self->{count_before} = $self->{_io}->read_s1();
    $self->{reserved_3} = $self->{_io}->read_u2le();
    $self->{reserved_4} = $self->{_io}->read_u2le();
    $self->{ref_wn} = $self->{_io}->read_u2le();
    $self->{ref_dn} = $self->{_io}->read_u1();
    $self->{count_after} = $self->{_io}->read_s1();
}

sub reserved_0 {
    my ($self) = @_;
    return $self->{reserved_0};
}

sub reserved_1 {
    my ($self) = @_;
    return $self->{reserved_1};
}

sub reserved_2 {
    my ($self) = @_;
    return $self->{reserved_2};
}

sub count_before {
    my ($self) = @_;
    return $self->{count_before};
}

sub reserved_3 {
    my ($self) = @_;
    return $self->{reserved_3};
}

sub reserved_4 {
    my ($self) = @_;
    return $self->{reserved_4};
}

sub ref_wn {
    my ($self) = @_;
    return $self->{ref_wn};
}

sub ref_dn {
    my ($self) = @_;
    return $self->{ref_dn};
}

sub count_after {
    my ($self) = @_;
    return $self->{count_after};
}

########################################################################
package Navigation::MsgGpsTimeDepA;

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

    $self->{wn} = $self->{_io}->read_u2le();
    $self->{tow} = $self->{_io}->read_u4le();
    $self->{ns_residual} = $self->{_io}->read_s4le();
    $self->{flags} = $self->{_io}->read_u1();
}

sub wn {
    my ($self) = @_;
    return $self->{wn};
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
}

sub ns_residual {
    my ($self) = @_;
    return $self->{ns_residual};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Navigation::MsgPosLlhGnss;

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

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{lat} = $self->{_io}->read_f8le();
    $self->{lon} = $self->{_io}->read_f8le();
    $self->{height} = $self->{_io}->read_f8le();
    $self->{h_accuracy} = $self->{_io}->read_u2le();
    $self->{v_accuracy} = $self->{_io}->read_u2le();
    $self->{n_sats} = $self->{_io}->read_u1();
    $self->{flags} = $self->{_io}->read_u1();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
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

sub h_accuracy {
    my ($self) = @_;
    return $self->{h_accuracy};
}

sub v_accuracy {
    my ($self) = @_;
    return $self->{v_accuracy};
}

sub n_sats {
    my ($self) = @_;
    return $self->{n_sats};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Navigation::MsgUtcTimeGnss;

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

    $self->{flags} = $self->{_io}->read_u1();
    $self->{tow} = $self->{_io}->read_u4le();
    $self->{year} = $self->{_io}->read_u2le();
    $self->{month} = $self->{_io}->read_u1();
    $self->{day} = $self->{_io}->read_u1();
    $self->{hours} = $self->{_io}->read_u1();
    $self->{minutes} = $self->{_io}->read_u1();
    $self->{seconds} = $self->{_io}->read_u1();
    $self->{ns} = $self->{_io}->read_u4le();
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
}

sub year {
    my ($self) = @_;
    return $self->{year};
}

sub month {
    my ($self) = @_;
    return $self->{month};
}

sub day {
    my ($self) = @_;
    return $self->{day};
}

sub hours {
    my ($self) = @_;
    return $self->{hours};
}

sub minutes {
    my ($self) = @_;
    return $self->{minutes};
}

sub seconds {
    my ($self) = @_;
    return $self->{seconds};
}

sub ns {
    my ($self) = @_;
    return $self->{ns};
}

########################################################################
package Navigation::MsgVelCog;

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

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{cog} = $self->{_io}->read_u4le();
    $self->{sog} = $self->{_io}->read_u4le();
    $self->{v_up} = $self->{_io}->read_s4le();
    $self->{cog_accuracy} = $self->{_io}->read_u4le();
    $self->{sog_accuracy} = $self->{_io}->read_u4le();
    $self->{v_up_accuracy} = $self->{_io}->read_u4le();
    $self->{flags} = $self->{_io}->read_u2le();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
}

sub cog {
    my ($self) = @_;
    return $self->{cog};
}

sub sog {
    my ($self) = @_;
    return $self->{sog};
}

sub v_up {
    my ($self) = @_;
    return $self->{v_up};
}

sub cog_accuracy {
    my ($self) = @_;
    return $self->{cog_accuracy};
}

sub sog_accuracy {
    my ($self) = @_;
    return $self->{sog_accuracy};
}

sub v_up_accuracy {
    my ($self) = @_;
    return $self->{v_up_accuracy};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Navigation::MsgBaselineNed;

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

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{n} = $self->{_io}->read_s4le();
    $self->{e} = $self->{_io}->read_s4le();
    $self->{d} = $self->{_io}->read_s4le();
    $self->{h_accuracy} = $self->{_io}->read_u2le();
    $self->{v_accuracy} = $self->{_io}->read_u2le();
    $self->{n_sats} = $self->{_io}->read_u1();
    $self->{flags} = $self->{_io}->read_u1();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
}

sub n {
    my ($self) = @_;
    return $self->{n};
}

sub e {
    my ($self) = @_;
    return $self->{e};
}

sub d {
    my ($self) = @_;
    return $self->{d};
}

sub h_accuracy {
    my ($self) = @_;
    return $self->{h_accuracy};
}

sub v_accuracy {
    my ($self) = @_;
    return $self->{v_accuracy};
}

sub n_sats {
    my ($self) = @_;
    return $self->{n_sats};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Navigation::MsgPosLlh;

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

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{lat} = $self->{_io}->read_f8le();
    $self->{lon} = $self->{_io}->read_f8le();
    $self->{height} = $self->{_io}->read_f8le();
    $self->{h_accuracy} = $self->{_io}->read_u2le();
    $self->{v_accuracy} = $self->{_io}->read_u2le();
    $self->{n_sats} = $self->{_io}->read_u1();
    $self->{flags} = $self->{_io}->read_u1();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
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

sub h_accuracy {
    my ($self) = @_;
    return $self->{h_accuracy};
}

sub v_accuracy {
    my ($self) = @_;
    return $self->{v_accuracy};
}

sub n_sats {
    my ($self) = @_;
    return $self->{n_sats};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Navigation::MsgBaselineHeadingDepA;

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

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{heading} = $self->{_io}->read_u4le();
    $self->{n_sats} = $self->{_io}->read_u1();
    $self->{flags} = $self->{_io}->read_u1();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
}

sub heading {
    my ($self) = @_;
    return $self->{heading};
}

sub n_sats {
    my ($self) = @_;
    return $self->{n_sats};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Navigation::MsgGpsTimeGnss;

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

    $self->{wn} = $self->{_io}->read_u2le();
    $self->{tow} = $self->{_io}->read_u4le();
    $self->{ns_residual} = $self->{_io}->read_s4le();
    $self->{flags} = $self->{_io}->read_u1();
}

sub wn {
    my ($self) = @_;
    return $self->{wn};
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
}

sub ns_residual {
    my ($self) = @_;
    return $self->{ns_residual};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Navigation::MsgBaselineEcefDepA;

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

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{x} = $self->{_io}->read_s4le();
    $self->{y} = $self->{_io}->read_s4le();
    $self->{z} = $self->{_io}->read_s4le();
    $self->{accuracy} = $self->{_io}->read_u2le();
    $self->{n_sats} = $self->{_io}->read_u1();
    $self->{flags} = $self->{_io}->read_u1();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
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

sub accuracy {
    my ($self) = @_;
    return $self->{accuracy};
}

sub n_sats {
    my ($self) = @_;
    return $self->{n_sats};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Navigation::MsgGpsTime;

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

    $self->{wn} = $self->{_io}->read_u2le();
    $self->{tow} = $self->{_io}->read_u4le();
    $self->{ns_residual} = $self->{_io}->read_s4le();
    $self->{flags} = $self->{_io}->read_u1();
}

sub wn {
    my ($self) = @_;
    return $self->{wn};
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
}

sub ns_residual {
    my ($self) = @_;
    return $self->{ns_residual};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Navigation::MsgDops;

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

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{gdop} = $self->{_io}->read_u2le();
    $self->{pdop} = $self->{_io}->read_u2le();
    $self->{tdop} = $self->{_io}->read_u2le();
    $self->{hdop} = $self->{_io}->read_u2le();
    $self->{vdop} = $self->{_io}->read_u2le();
    $self->{flags} = $self->{_io}->read_u1();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
}

sub gdop {
    my ($self) = @_;
    return $self->{gdop};
}

sub pdop {
    my ($self) = @_;
    return $self->{pdop};
}

sub tdop {
    my ($self) = @_;
    return $self->{tdop};
}

sub hdop {
    my ($self) = @_;
    return $self->{hdop};
}

sub vdop {
    my ($self) = @_;
    return $self->{vdop};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Navigation::MsgPosEcefDepA;

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

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{x} = $self->{_io}->read_f8le();
    $self->{y} = $self->{_io}->read_f8le();
    $self->{z} = $self->{_io}->read_f8le();
    $self->{accuracy} = $self->{_io}->read_u2le();
    $self->{n_sats} = $self->{_io}->read_u1();
    $self->{flags} = $self->{_io}->read_u1();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
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

sub accuracy {
    my ($self) = @_;
    return $self->{accuracy};
}

sub n_sats {
    my ($self) = @_;
    return $self->{n_sats};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

########################################################################
package Navigation::EstimatedHorizontalErrorEllipse;

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

    $self->{semi_major} = $self->{_io}->read_f4le();
    $self->{semi_minor} = $self->{_io}->read_f4le();
    $self->{orientation} = $self->{_io}->read_f4le();
}

sub semi_major {
    my ($self) = @_;
    return $self->{semi_major};
}

sub semi_minor {
    my ($self) = @_;
    return $self->{semi_minor};
}

sub orientation {
    my ($self) = @_;
    return $self->{orientation};
}

########################################################################
package Navigation::MsgPosLlhAcc;

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

    $self->{tow} = $self->{_io}->read_u4le();
    $self->{lat} = $self->{_io}->read_f8le();
    $self->{lon} = $self->{_io}->read_f8le();
    $self->{height} = $self->{_io}->read_f8le();
    $self->{orthometric_height} = $self->{_io}->read_f8le();
    $self->{h_accuracy} = $self->{_io}->read_f4le();
    $self->{v_accuracy} = $self->{_io}->read_f4le();
    $self->{ct_accuracy} = $self->{_io}->read_f4le();
    $self->{at_accuracy} = $self->{_io}->read_f4le();
    $self->{h_ellipse} = Navigation::EstimatedHorizontalErrorEllipse->new($self->{_io}, $self, $self->{_root});
    $self->{confidence_and_geoid} = $self->{_io}->read_u1();
    $self->{n_sats} = $self->{_io}->read_u1();
    $self->{flags} = $self->{_io}->read_u1();
}

sub tow {
    my ($self) = @_;
    return $self->{tow};
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

sub orthometric_height {
    my ($self) = @_;
    return $self->{orthometric_height};
}

sub h_accuracy {
    my ($self) = @_;
    return $self->{h_accuracy};
}

sub v_accuracy {
    my ($self) = @_;
    return $self->{v_accuracy};
}

sub ct_accuracy {
    my ($self) = @_;
    return $self->{ct_accuracy};
}

sub at_accuracy {
    my ($self) = @_;
    return $self->{at_accuracy};
}

sub h_ellipse {
    my ($self) = @_;
    return $self->{h_ellipse};
}

sub confidence_and_geoid {
    my ($self) = @_;
    return $self->{confidence_and_geoid};
}

sub n_sats {
    my ($self) = @_;
    return $self->{n_sats};
}

sub flags {
    my ($self) = @_;
    return $self->{flags};
}

1;
