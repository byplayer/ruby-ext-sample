require 'spec_helper'

describe HashSample do
  context "new key" do
    subject { HashSample.new }
    it { subject.make_hash.class.should == Hash }
  end
end
